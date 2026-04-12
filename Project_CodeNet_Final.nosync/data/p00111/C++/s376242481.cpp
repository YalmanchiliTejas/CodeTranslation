#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <fstream>
#include <sstream>
#include <math.h>
#include <queue>
#include <stack>

using namespace std;

string code[200];








int main(){
    code['A'] = "00000";
    code['B'] = "00001";
    code['C'] = "00010";
    code['D'] = "00011";
    code['E'] = "00100";
    code['F'] = "00101";
    code['G'] = "00110";
    code['H'] = "00111";
    code['I'] = "01000";
    code['J'] = "01001";
    code['K'] = "01010";
    code['L'] = "01011";
    code['M'] = "01100";
    code['N'] = "01101";
    code['O'] = "01110";
    code['P'] = "01111";
    code['Q'] = "10000";
    code['R'] = "10001";
    code['S'] = "10010";
    code['T'] = "10011";
    code['U'] = "10100";
    code['V'] = "10101";
    code['W'] = "10110";
    code['X'] = "10111";
    code['Y'] = "11000";
    code['Z'] = "11001";
    code[' '] = "11010";
    code['.'] = "11011";
    code[','] = "11100";
    code['-'] = "11101";
    code['\'']= "11110";
    code['?'] = "11111";
    
    map<string,string> code2;
    code2["101"] = " ";
    code2["000000"] = "\'";
    code2["000011"] = ",";
    code2["10010001"] = "-";
    code2["010001"] = ".";
    code2["000001"] = "?";
    code2["100101"] = "A";
    code2["10011010"] = "B";
    code2["0101"] = "C";
    code2["0001"] = "D";
    code2["110"] = "E";
    code2["01001"] = "F";
    code2["10011011"] = "G";
    code2["010000"] = "H";
    code2["0111"] = "I";
    code2["10011000"] = "J";
    code2["0110"] = "K";
    code2["00100"] = "L";
    code2["10011001"] = "M";
    code2["10011110"] = "N";
    code2["00101"] = "O";
    code2["111"] = "P";
    code2["10011111"] = "Q";
    code2["1000"] = "R";
    code2["00110"] = "S";
    code2["00111"] = "T";
    code2["10011100"] = "U";
    code2["10011101"] = "V";
    code2["000010"] = "W";
    code2["10010010"] = "X";
    code2["10010011"] = "Y";
    code2["10010000"] = "Z";
    
    
    string s;
    while(getline(cin,s)){
        string n,ret;
        for(int i=0; i<s.length(); i++){
            n+=code[s[i]];
        }
        //cout<<n<<endl;
        
        s.erase();
        while(n.length()!=0){
            s+=n[0];
            n.erase(0,1);
            if(code2.count(s)){
                ret+=code2[s];
                s.erase();
            }
        }
        cout<<ret<<endl;
        s.erase();
    }
}