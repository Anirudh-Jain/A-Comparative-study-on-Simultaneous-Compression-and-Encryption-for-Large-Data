#include <iostream>
#include <fstream>
#include "huffmanEncoding.hpp"

using namespace std;

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        cout << argc << endl;
        cout << "Proper syntax: ./a <input filename1>";
        return 0;
    }

    // Instantiating File Object for reading
    string filename(argv[1]);
    string inPath = "./Input Data/" + filename;
    ifstream file_input(inPath, ios::binary);

    // Instantiating File Object for writing
    string outfile = "";
    int i = 0;
    while (filename[i] != '.')
    {
        outfile.push_back(filename[i++]);
    }
    string outPath = "./Output/" + outfile + ".dat";
    ofstream clone(outPath, ios::binary);

    if (!file_input.is_open())
    {
        cout << "File not found in the directory." << endl;
        return 0;
    }

    // Checking character frequencies in the input file
    unordered_map<char, ll> charFreq;
    while (file_input)
    {
        charFreq[file_input.get()]++;
    }

    // Instantiating encoder
    Encode encoder;
    unordered_map<char, string> encodings = encoder.huffman(charFreq);

    // Testing / Debugging Starts --------------------------------
    cout << "Mappings:-" << endl;
    for (auto pair : encodings)
    {
        cout << pair.first << " --> " << pair.second << endl;
    }
    // Testing / Debugging Ends ----------------------------------

    return 0;
}