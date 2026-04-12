#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, char> mpp1;
map<string, bool> mpp2;
map<char, string> conv;

void makeMap()
{
  conv['A'] = "00000";
  conv['B'] = "00001";
  conv['C'] = "00010";
  conv['D'] = "00011";
  conv['E'] = "00100";
  conv['F'] = "00101";
  conv['G'] = "00110";
  conv['H'] = "00111";
  conv['I'] = "01000";
  conv['J'] = "01001";
  conv['K'] = "01010";
  conv['L'] = "01011";
  conv['M'] = "01100";
  conv['N'] = "01101";
  conv['O'] = "01110";
  conv['P'] = "01111";
  conv['Q'] = "10000";
  conv['R'] = "10001";
  conv['S'] = "10010";
  conv['T'] = "10011";
  conv['U'] = "10100";
  conv['V'] = "10101";
  conv['W'] = "10110";
  conv['X'] = "10111";
  conv['Y'] = "11000";
  conv['Z'] = "11001";
  conv[' '] = "11010";
  conv['.'] = "11011";
  conv[','] = "11100";
  conv['-'] = "11101";
  conv['\''] = "11110";
  conv['?'] = "11111";

  mpp1["101"] = ' ';
  mpp2["101"] = true;
  mpp1["000000"] = '\'';
  mpp2["000000"] = true;
  mpp1["000011"] = ',';
  mpp2["000011"] = true;
  mpp1["10010001"] = '-';
  mpp2["10010001"] = true;
  mpp1["010001"] = '.';
  mpp2["010001"] = true;
  mpp1["000001"] = '?';
  mpp2["000001"] = true;
  mpp1["100101"] = 'A';
  mpp2["100101"] = true;
  mpp1["10011010"] = 'B';
  mpp2["10011010"] = true;
  mpp1["0101"] = 'C';
  mpp2["0101"] = true;
  mpp1["0001"] = 'D';
  mpp2["0001"] = true;
  mpp1["110"] = 'E';
  mpp2["110"] = true;
  mpp1["01001"] = 'F';
  mpp2["01001"] = true;
  mpp1["10011011"] = 'G';
  mpp2["10011011"] = true;
  mpp1["010000"] = 'H';
  mpp2["010000"] = true;
  mpp1["0111"] = 'I';
  mpp2["0111"] = true;
  mpp1["10011000"] = 'J';
  mpp2["10011000"] = true;
  mpp1["0110"] = 'K';
  mpp2["0110"] = true;
  mpp1["00100"] = 'L';
  mpp2["00100"] = true;
  mpp1["10011001"] = 'M';
  mpp2["10011001"] = true;
  mpp1["10011110"] = 'N';
  mpp2["10011110"] = true;
  mpp1["00101"] = 'O';
  mpp2["00101"] = true;
  mpp1["111"] = 'P';
  mpp2["111"] = true;
  mpp1["10011111"] = 'Q';
  mpp2["10011111"] = true;
  mpp1["1000"] = 'R';
  mpp2["1000"] = true;
  mpp1["00110"] = 'S';
  mpp2["00110"] = true;
  mpp1["00111"] = 'T';
  mpp2["00111"] = true;
  mpp1["10011100"] = 'U';
  mpp2["10011100"] = true;
  mpp1["10011101"] = 'V';
  mpp2["10011101"] = true;
  mpp1["000010"] = 'W';
  mpp2["000010"] = true;
  mpp1["10010010"] = 'X';
  mpp2["10010010"] = true;
  mpp1["10010011"] = 'Y';
  mpp2["10010011"] = true;
  mpp1["10010000"] = 'Z';
  mpp2["10010000"] = true;

  return ;
}

int main()
{
  string str, str2, str3, str4;

  makeMap();
  while(!cin.eof() && getline(cin, str)){
    str2 = str3 = str4 = "";
    for(int i = 0; i < str.size(); i++){
      str2 += conv[str[i]];
    }

    for(int i = 0; i < str2.size(); i++){
      str4 += str2[i];
      if(mpp2[str4]){
	str3 += mpp1[str4];
	str4 = "";
      }
    }

    cout << str3 << endl;
  }

  return 0;
}