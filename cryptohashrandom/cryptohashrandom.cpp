#include <iostream>
#include <D:\Project\VS2019\Labs\cryptopp850\sha.h>
#include <string>
#include <iomanip>

using namespace std;
using namespace CryptoPP;

#include <D:\Project\VS2019\Labs\cryptopp850\hex.h>
using CryptoPP::HexEncoder;
#include <D:\Project\VS2019\Labs\cryptopp850\filters.h>
using CryptoPP::StringSink;

#define WORD_SIZE 5
#define H_PART 5
#define AMOUNT 20

string hashSHA256(string message)
{
    SHA256 hash;
    string digest;
    StringSource s(message, true, new HashFilter(hash, new HexEncoder(new StringSink(digest))));
    return digest;
}


int main(int argc, char* argv[]) {
    cout << setw(10) << "Hash part";
    cout << setw(20) << "Random numeral"<< endl;
    for (int i = 0; i < AMOUNT; i++) {
        string sha256 = hashSHA256(to_string(i));
        string hashPart = sha256.substr(0, H_PART);
        cout << setw(10) << hashPart;
        cout << setw(20) << strtol(hashPart.c_str(), NULL, 16) << endl;
    }
    
    system("pause");

    return 0;
}