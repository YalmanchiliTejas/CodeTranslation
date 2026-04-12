#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <climits>
#include <cfloat>
using namespace std;

int main()
{
    map<string, char> code;
    code["101"] =      ' ';
    code["000000"] =   '\'';
    code["000011"] =   ',';
    code["10010001"] = '-';
    code["010001"] =   '.';
    code["000001"] =   '?';
    code["100101"] =   'A';
    code["10011010"] = 'B';
    code["0101"] =     'C';
    code["0001"] =     'D';
    code["110"] =      'E';
    code["01001"] =    'F';
    code["10011011"] = 'G';
    code["010000"] =   'H';
    code["0111"] =     'I';
    code["10011000"] = 'J';
    code["0110"] =     'K';
    code["00100"] =    'L';
    code["10011001"] = 'M';
    code["10011110"] = 'N';
    code["00101"] =    'O';
    code["111"] =      'P';
    code["10011111"] = 'Q';
    code["1000"] =     'R';
    code["00110"] =    'S';
    code["00111"] =    'T';
    code["10011100"] = 'U';
    code["10011101"] = 'V';
    code["000010"] =   'W';
    code["10010010"] = 'X';
    code["10010011"] = 'Y';
    code["10010000"] = 'Z';

    for(;;){
        string s;
        if(!getline(cin, s))
            return 0;

        int n = s.size();
        string s1;
        for(int i=0; i<n; ++i){
            if('A' <= s[i] && s[i] <= 'Z')
                s1 += bitset<5>(s[i]-'A').to_string();
            else if(s[i] == ' ')
                s1 += "11010";
            else if(s[i] == '.')
                s1 += "11011";
            else if(s[i] == ',')
                s1 += "11100";
            else if(s[i] == '-')
                s1 += "11101";
            else if(s[i] == '\'')
                s1 += "11110";
            else
                s1 += "11111";
        }

        n = s1.size();
        int i = 0;
        int j = 0;
        while(j < n){
            map<string, char>::iterator it;
            it = code.find(s1.substr(i, j-i+1));
            if(it == code.end())
                ++ j;
            else{
                cout << it->second;
                i = ++ j;
            }
        }
        cout << endl;
    }
}