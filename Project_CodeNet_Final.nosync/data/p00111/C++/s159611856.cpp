#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <string>
#include <sstream>
#include <stack>
#include <iomanip>
#include <numeric>
#include <queue>
#include <climits>
#include <set>
#include <complex>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;
using ll = long long;
#define MOD 1000000007
#define INF 1LL << 59
using ld = long double;

bool operator<(const pair<int, int> &a, const pair<int, int> &b)
{
    if (a.first == b.first)
    {
        return b.second > a.second;
    }
    return a.first < b.first;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    //cout << fixed << setprecision(5);
    map<char, string> mp2;
    mp2['A'] = "00000";
    mp2['B'] = "00001";
    mp2['C'] = "00010";
    mp2['D'] = "00011";
    mp2['E'] = "00100";
    mp2['F'] = "00101";
    mp2['G'] = "00110";
    mp2['H'] = "00111";

    mp2['I'] = "01000";
    mp2['J'] = "01001";
    mp2['K'] = "01010";
    mp2['L'] = "01011";
    mp2['M'] = "01100";
    mp2['N'] = "01101";
    mp2['O'] = "01110";
    mp2['P'] = "01111";

    mp2['Q'] = "10000";
    mp2['R'] = "10001";
    mp2['S'] = "10010";
    mp2['T'] = "10011";
    mp2['U'] = "10100";
    mp2['V'] = "10101";
    mp2['W'] = "10110";
    mp2['X'] = "10111";

    mp2['Y'] = "11000";
    mp2['Z'] = "11001";
    mp2[' '] = "11010";
    mp2['.'] = "11011";
    mp2[','] = "11100";
    mp2['-'] = "11101";
    mp2['\''] = "11110";
    mp2['?'] = "11111";

    map<string, char> mp1;
    mp1["101"] = ' ';
    mp1["000000"] = '\'';
    mp1["000011"] = ',';
    mp1["10010001"] = '-';
    mp1["010001"] = '.';
    mp1["000001"] = '?';
    mp1["100101"] = 'A';
    mp1["10011010"] = 'B';
    mp1["0101"] = 'C';
    mp1["0001"] = 'D';
    mp1["110"] = 'E';
    mp1["01001"] = 'F';
    mp1["10011011"] = 'G';
    mp1["010000"] = 'H';
    mp1["0111"] = 'I';
    mp1["10011000"] = 'J';
    mp1["0110"] = 'K';
    mp1["00100"] = 'L';
    mp1["10011001"] = 'M';
    mp1["10011110"] = 'N';
    mp1["00101"] = 'O';
    mp1["111"] = 'P';
    mp1["10011111"] = 'Q';
    mp1["1000"] = 'R';
    mp1["00110"] = 'S';
    mp1["00111"] = 'T';
    mp1["10011100"] = 'U';
    mp1["10011101"] = 'V';
    mp1["000010"] = 'W';
    mp1["10010010"] = 'X';
    mp1["10010011"] = 'Y';
    mp1["10010000"] = 'Z';
    string s;
    while (getline(cin, s))
    {
        string code = "";
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            code += mp2[s[i]];
        }
        //cout << code << endl;

        int m = code.size();
        string ans = "";

        for (int i = 0; i < m; ++i)
        {
            ans += code[i];
            if (mp1.find(ans) != mp1.end())
            {
                cout << mp1[ans];
                ans = "";
            }
        }
        cout << endl;
    }
    return 0;
}
