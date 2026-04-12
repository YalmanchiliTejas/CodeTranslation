#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(){
  string s;
  map<string,string> word;
  word["101"] = " ";
  word["000000"] = "\'";
  word["000011"] = ",";
  word["10010001"] = "-";
  word["010001"] = ".";
  word["000001"] = "?";
  word["100101"] = "A";
  word["10011010"] = "B";
  word["0101"] = "C";
  word["0001"] = "D";
  word["110"] = "E";
  word["01001"] = "F";
  word["10011011"] = "G";
  word["010000"] = "H";
  word["0111"] = "I";
  word["10011000"] = "J";
  word["0110"] = "K";
  word["00100"] = "L";
  word["10011001"] = "M";
  word["10011110"] = "N";
  word["00101"] = "O";
  word["111"] = "P";
  word["10011111"] = "Q";
  word["1000"] = "R";
  word["00110"] = "S";
  word["00111"] = "T";
  word["10011100"] = "U";
  word["10011101"] = "V";
  word["000010"] = "W";
  word["10010010"] = "X";
  word["10010011"] = "Y";
  word["10010000"] = "Z";
  while(getline(cin,s)){
    string x,y,z;
    int r = 0;
    for(int i=0; i<s.size(); i++){
      if(s[i] == 'A'){x+="00000";}
      if(s[i] == 'B'){x+="00001";}
      if(s[i] == 'C'){x+="00010";}
      if(s[i] == 'D'){x+="00011";}
      if(s[i] == 'E'){x+="00100";}
      if(s[i] == 'F'){x+="00101";}
      if(s[i] == 'G'){x+="00110";}
      if(s[i] == 'H'){x+="00111";}
      if(s[i] == 'I'){x+="01000";}
      if(s[i] == 'J'){x+="01001";}
      if(s[i] == 'K'){x+="01010";}
      if(s[i] == 'L'){x+="01011";}
      if(s[i] == 'M'){x+="01100";}
      if(s[i] == 'N'){x+="01101";}
      if(s[i] == 'O'){x+="01110";}
      if(s[i] == 'P'){x+="01111";}
      if(s[i] == 'Q'){x+="10000";}
      if(s[i] == 'R'){x+="10001";}
      if(s[i] == 'S'){x+="10010";}
      if(s[i] == 'T'){x+="10011";}
      if(s[i] == 'U'){x+="10100";}
      if(s[i] == 'V'){x+="10101";}
      if(s[i] == 'W'){x+="10110";}
      if(s[i] == 'X'){x+="10111";}
      if(s[i] == 'Y'){x+="11000";}
      if(s[i] == 'Z'){x+="11001";}
      if(s[i] == ' '){x+="11010";}
      if(s[i] == '.'){x+="11011";}
      if(s[i] == ','){x+="11100";}
      if(s[i] == '-'){x+="11101";}
      if(s[i] == '\''){x+="11110";}
      if(s[i] == '?'){x+="11111";}
    }
    for(int i=0; i<x.size(); i++){
      y+=x[i];
      z+=word[y];
      if(r != z.size()){r = z.size();y.clear();}
    }
    cout <<z<<endl;
  }
  return 0;
}