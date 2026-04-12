#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) range(i,0,b)
#define pb(a) push_back(a)
#define all(a) (a).begin(), (a).end()
#define debug(x) cout << "debug " << x << endl;
using namespace std;

map<char, string> enc;
map<string, char> word;

void inputData(){
    enc['A'] = "00000";
    enc['B'] = "00001";
    enc['C'] = "00010";
    enc['D'] = "00011";
    enc['E'] = "00100";
    enc['F'] = "00101";
    enc['G'] = "00110";
    enc['H'] = "00111";
    enc['I'] = "01000";
    enc['J'] = "01001";
    enc['K'] = "01010";
    enc['L'] = "01011";
    enc['M'] = "01100";
    enc['N'] = "01101";
    enc['O'] = "01110";
    enc['P'] = "01111";
    enc['Q'] = "10000";
    enc['R'] = "10001";
    enc['S'] = "10010";
    enc['T'] = "10011";
    enc['U'] = "10100";
    enc['V'] = "10101";
    enc['W'] = "10110";
    enc['X'] = "10111";
    enc['Y'] = "11000";
    enc['Z'] = "11001";
    enc[' '] = "11010";
    enc['.'] = "11011";
    enc[','] = "11100";
    enc['-'] = "11101";
    enc['\''] = "11110";
    enc['?'] = "11111";
    word["101"] = ' ';
    word["000000"] = '\'';
    word["000011"] = ',';
    word["10010001"] = '-';
    word["010001"] = '.';
    word["000001"] = '?';
    word["100101"] = 'A';
    word["10011010"] = 'B';
    word["0101"] = 'C';
    word["0001"] = 'D';
    word["110"] = 'E';
    word["01001"] = 'F';
    word["10011011"] = 'G';
    word["010000"] = 'H';
    word["0111"] = 'I';
    word["10011000"] = 'J';
    word["0110"] = 'K';
    word["00100"] = 'L';
    word["10011001"] = 'M';
    word["10011110"] = 'N';
    word["00101"] = 'O';
    word["111"] = 'P';
    word["10011111"] = 'Q';
    word["1000"] = 'R';
    word["00110"] = 'S';
    word["00111"] = 'T';
    word["10011100"] = 'U';
    word["10011101"] = 'V';
    word["000010"] = 'W';
    word["10010010"] = 'X';
    word["10010011"] = 'Y';
    word["10010000"] = 'Z';
}

string changeWord(string s){
    string sentence,a;
    rep(i,s.size()){
        a+=s[i];
        if((word[a] >= 'A'&& word[a] <= 'Z') || word[a] == ' ' || word[a] == '\'' || word[a] == ',' || word[a] == '-' || word[a] == '.' || word[a] == '?'){
            sentence+=word[a];
            a = "";
        }
    }
    return sentence;
}

string changeCode(string s){
    string code;
    rep(i,s.size()){
        code+=enc[s[i]];
    }
    return code;
}

int main(){
    inputData();
    string s;
    while(getline(cin,s)){
        cout << changeWord(changeCode(s)) << endl;;
    }
}