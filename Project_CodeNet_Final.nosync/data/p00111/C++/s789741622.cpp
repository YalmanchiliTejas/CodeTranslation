#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string,string> code1,code2;

int main() {
    code1["A"] = "00000"; code1["B"] = "00001";
    code1["C"] = "00010"; code1["D"] = "00011";
    code1["E"] = "00100"; code1["F"] = "00101";
    code1["H"] = "00111"; code1["G"] = "00110";
    code1["I"] = "01000"; code1["J"] = "01001";
    code1["K"] = "01010"; code1["L"] = "01011";
    code1["M"] = "01100"; code1["N"] = "01101";
    code1["O"] = "01110"; code1["P"] = "01111";
    code1["Q"] = "10000"; code1["R"] = "10001";
    code1["S"] = "10010"; code1["T"] = "10011";
    code1["U"] = "10100"; code1["V"] = "10101";
    code1["W"] = "10110"; code1["X"] = "10111";
    code1["Y"] = "11000"; code1["Z"] = "11001";
    code1[" "] = "11010"; code1["."] = "11011";
    code1[","] = "11100"; code1["-"] = "11101";
    code1["'"] = "11110"; code1["?"] = "11111";

    code2["101"] = " "; code2["000000"] = "'"; code2["000011"] = ",";
    code2["10010001"] = "-"; code2["010001"] = "."; code2["000001"] = "?";
    code2["100101"] = "A"; code2["10011010"] = "B"; code2["0101"] = "C";
    code2["0001"] = "D"; code2["110"] = "E"; code2["01001"] = "F";
    code2["10011011"] = "G"; code2["010000"] = "H"; code2["0111"] = "I";
    code2["10011000"] = "J"; code2["0110"] = "K"; code2["00100"] = "L";
    code2["10011001"] = "M"; code2["10011110"] = "N"; code2["00101"] = "O";
    code2["111"] = "P"; code2["10011111"] = "Q"; code2["1000"] = "R";
    code2["00110"] = "S"; code2["00111"] = "T"; code2["10011100"] = "U";
    code2["10011101"] = "V";  code2["000010"] = "W"; code2["10010010"] = "X";
    code2["10010011"] = "Y"; code2["10010000"] = "Z";

    string input;
    while(getline(cin, input)) {
        string tr1 = "";
        for(int i=0; i<input.length(); ++i) tr1 += code1[string(1,input[i])];
        string tmp = "",res = "";
        for(int i=0; i<tr1.length(); ++i) {
            tmp += string(1,tr1[i]);
            if(code2.find(tmp) != code2.end()) {
                res += code2[tmp];
                tmp = "";
            }
        }

        cout<<res<<endl;
    }
}