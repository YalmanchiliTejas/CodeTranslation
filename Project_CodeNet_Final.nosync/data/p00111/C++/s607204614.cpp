#include <iostream>
#include <cstdio>
#include <vector>
#include <list>
#include <algorithm>
#include <cmath>
#include <stack>
#include <map>
#include <numeric>
#include <sstream>
#include <queue>
#include <iomanip>
using namespace std;

#define REP(i,n) for(int (i)=0; (i)<(n); (i)++)
#define FOR(i,a,b) for(int (i)=(a); (i)<(b); (i)++)
#define PUSH(n,v) for(int i=0; i<(n); i++) {int j; cin >> j; v.push_back(j);}
#define ALL(v) v.begin(), v.end()
#define print(s) cout << (s) << endl

#define eadd(a,b) encode[(b)] = (a)
#define dadd(a,b) decode[(b)] = (a)

map<string, char> encode;
map<char, string> decode;

void solve111(string s) {
    string t = "";
    REP(i,s.size()) {
        t += decode[s[i]];
    }
    string ans = "";
    while (t.size()) {
        string c = "";
        c += t[0];
        c += t[1];
        c += t[2];
        int i = 3;
        while (encode.find(c) == encode.end()) {
            if (i >= t.size()) {
                c = "end";
                t = "";
                break;
            }
            c += t[i++];
        }
        if (c != "end") {
            ans += encode[c];
            REP(j,i) {
                t.erase(t.begin());
            }
        }
    }
    cout << ans << endl;
}

int main() {
    eadd(' ',"101");
    eadd('\'',"000000");
    eadd(',',"000011");
    eadd('-',"10010001");
    eadd('.',"010001");
    eadd('?',"000001");
    eadd('A',"100101");
    eadd('B',"10011010");
    eadd('C',"0101");
    eadd('D',"0001");
    eadd('E',"110");
    eadd('F',"01001");
    eadd('G',"10011011");
    eadd('H',"010000");
    eadd('I',"0111");
    eadd('J',"10011000");
    eadd('K',"0110");
    eadd('L',"00100");
    eadd('M',"10011001");
    eadd('N',"10011110");
    eadd('O',"00101");
    eadd('P',"111");
    eadd('Q',"10011111");
    eadd('R',"1000");
    eadd('S',"00110");
    eadd('T',"00111");
    eadd('U',"10011100");
    eadd('V',"10011101");
    eadd('W',"000010");
    eadd('X',"10010010");
    eadd('Y',"10010011");
    eadd('Z',"10010000");
    
    dadd("00000",'A');
    dadd("00001",'B');
    dadd("00010",'C');
    dadd("00011",'D');
    dadd("00100",'E');
    dadd("00101",'F');
    dadd("00110",'G');
    dadd("00111",'H');
    dadd("01000",'I');
    dadd("01001",'J');
    dadd("01010",'K');
    dadd("01011",'L');
    dadd("01100",'M');
    dadd("01101",'N');
    dadd("01110",'O');
    dadd("01111",'P');
    dadd("10000",'Q');
    dadd("10001",'R');
    dadd("10010",'S');
    dadd("10011",'T');
    dadd("10100",'U');
    dadd("10101",'V');
    dadd("10110",'W');
    dadd("10111",'X');
    dadd("11000",'Y');
    dadd("11001",'Z');
    dadd("11010",' ');
    dadd("11011",'.');
    dadd("11100",',');
    dadd("11101",'-');
    dadd("11110",'\'');
    dadd("11111",'?');
    
    string s;
    while (getline(cin,s)) {
        solve111(s);
    }
    return 0;
}