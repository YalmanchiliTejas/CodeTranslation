#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string pat = "ABCDEFGHIJKLMNOPQRSTUVWXYZ .,-'?";
string board[] = {"100101", "10011010", "0101", "0001",
            "110", "01001", "10011011", "010000",
            "0111", "10011000", "0110", "00100",
            "10011001", "10011110", "00101", "111",
            "10011111", "1000", "00110", "00111",
            "10011100", "10011101", "000010", "10010010",
            "10010011", "10010000", "101", "010001",
            "000011", "10010001", "000000", "000001"};

int main() {
    string s; 
    while(getline(cin, s)) {
        string gen = "";
        for(size_t i=0; i<s.length(); i++) {
            int c = pat.find(s[i]);
            string tmp = "";
            for(int j=0; j<5; j++) {
                if(c & 1) tmp += '1';
                else tmp += '0';
                c >>= 1;
            }
            reverse(tmp.begin(), tmp.end());
            gen += tmp;
        }

        string tmp = "", ans = "";
        for(size_t i=0; i<gen.length(); i++) {
            tmp += gen[i];
            for(int j=0; j<32; j++) {
                if(board[j] == tmp) {
                    ans += pat[j];
                    tmp = "";
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}