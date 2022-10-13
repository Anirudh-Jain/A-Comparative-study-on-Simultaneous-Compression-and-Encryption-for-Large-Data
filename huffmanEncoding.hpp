#include <queue>
#include <string>
#include <vector>
#include <unordered_map>
#define ll unsigned long long

using namespace std;

class Node
{
public:
    int freq;
    char ch;
    Node *left;
    Node *right;

    Node(int val, char character)
    {
        freq = val;
        ch = character;
        left = NULL;
        right = NULL;
    }
};

class compare
{
    bool operator()(Node *a, Node *b)
    {
        return (a->freq) > (b->freq);
    }
};

class Encode
{
private:
    void traverse(Node *root, unordered_map<char, string> &ans, string temp)
    {
        if (root->left == NULL && root->right == NULL)
        {
            ans[root->ch] = temp;
            temp = "";
            return;
        }

        traverse(root->left, ans, temp + '0');
        traverse(root->right, ans, temp + '1');
    }

public:
    unordered_map<char, string> huffman(unordered_map<char, ll> &charFreq)
    {
        priority_queue<Node *, vector<Node *>, greater<Node *>> minhp;
        for (auto pair : charFreq)
        {
            Node *nxt = new Node(pair.second, pair.first);
            minhp.push(nxt);
            pair.second;
        }

        while (minhp.size() > 1)
        {
            Node *min1 = minhp.top();
            minhp.pop();

            Node *min2 = minhp.top();
            minhp.pop();

            Node *sum = new Node(min1->freq + min2->freq, '\0');
            sum->left = min1;
            sum->right = min2;

            minhp.push(sum);
        }

        Node *root = minhp.top();
        unordered_map<char, string> ans;
        string temp = "";
        traverse(root, ans, temp);
        return ans;
    }
};
