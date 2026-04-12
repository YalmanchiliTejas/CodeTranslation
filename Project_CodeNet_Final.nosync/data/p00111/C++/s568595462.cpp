#include <iostream>
#include <cctype>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

void initialize(void);

map<char, int> code;
map<string, char> decod;

int main()
{
    string inp;
  
    initialize();
  
    while (getline(cin, inp)) {
        int dig;
        string tmp;
        string deco;
        
        for (int i = 0; i < inp.size(); i++) {
            if (isalpha(inp[i]))
                dig = inp[i] - 'A';
            else
                dig = code[inp[i]];
            
            for (int i = 0; i < 5; i++) {
                if (dig % 2 == 1)
                    tmp += '1';
                else if (dig % 2 == 0)
                    tmp += '0';
                dig /= 2;
            }
            reverse(tmp.begin(), tmp.end());
            deco += tmp;
            tmp.clear();
        }

        map<string, char>::iterator itr;
        for (int i = 0; i < deco.size(); i++) {
            for (int j = 1; j <= 8; j++) {
                string tmp2 = deco.substr(i, j);
                itr = decod.find(tmp2);
                if (itr != decod.end()) {
                    cout << decod[tmp2];
                    i += j - 1;
                    break;
                }
            }
        }
        cout << endl;
    }

    return 0;
}


void initialize(void)
{
    code.insert(pair<char, int>(' ', 26));
    code.insert(pair<char, int>('.', 27));
    code.insert(pair<char, int>(',', 28));
    code.insert(pair<char, int>('-', 29));
    code.insert(pair<char, int>('\'', 30));
    code.insert(pair<char, int>('?', 31));

    decod.insert(pair<string, char>("101", ' '));
    decod.insert(pair<string, char>("000000", '\''));
    decod.insert(pair<string, char>("000011", ','));
    decod.insert(pair<string, char>("10010001", '-'));
    decod.insert(pair<string, char>("010001", '.'));
    decod.insert(pair<string, char>("000001", '?'));
    decod.insert(pair<string, char>("100101", 'A'));
    decod.insert(pair<string, char>("10011010", 'B'));

    decod.insert(pair<string, char>("0101", 'C'));
    decod.insert(pair<string, char>("0001", 'D'));
    decod.insert(pair<string, char>("110", 'E'));
    decod.insert(pair<string, char>("01001", 'F'));
    decod.insert(pair<string, char>("10011011", 'G'));
    decod.insert(pair<string, char>("010000", 'H'));
    decod.insert(pair<string, char>("0111", 'I'));
    decod.insert(pair<string, char>("10011000", 'J'));

    decod.insert(pair<string, char>("0110", 'K'));
    decod.insert(pair<string, char>("00100", 'L'));
    decod.insert(pair<string, char>("10011001", 'M'));
    decod.insert(pair<string, char>("10011110", 'N'));
    decod.insert(pair<string, char>("00101", 'O'));
    decod.insert(pair<string, char>("111", 'P'));
    decod.insert(pair<string, char>("10011111", 'Q'));
    decod.insert(pair<string, char>("1000", 'R'));

    decod.insert(pair<string, char>("00110", 'S'));
    decod.insert(pair<string, char>("00111", 'T'));
    decod.insert(pair<string, char>("10011100", 'U'));
    decod.insert(pair<string, char>("10011101", 'V'));
    decod.insert(pair<string, char>("000010", 'W'));
    decod.insert(pair<string, char>("10010010", 'X'));
    decod.insert(pair<string, char>("10010011", 'Y'));
    decod.insert(pair<string, char>("10010000", 'Z'));

}