#include <iostream>
#include <map>

using namespace std;

string compute(int i){

  string S = "";
  while(i){
    S = static_cast<char>(i % 2 + '0') + S;
    i /= 2;
  }
  while(S.size() < 5 ){
    S = '0' + S;
  }
  return S;
}

int main(void){

  map<char,string> input;
  map<string,char> output;
  
  output["101"] = ' ';
  output["000000"] = '\'';
  output["000011"] = ',';
  output["10010001"] = '-';
  output["010001"] = '.';
  output["000001"] = '?';
  output["100101"] = 'A';
  output["10011010"] = 'B';
  output["0101"] = 'C';
  output["0001"] = 'D';
  output["110"] = 'E';
  output["01001"] = 'F';
  output["10011011"] = 'G';
  output["010000"] = 'H';
  output["0111"] = 'I';
  output["10011000"] = 'J';
  output["0110"] = 'K';
  output["00100"] = 'L';
  output["10011001"] = 'M';
  output["10011110"] = 'N';
  output["00101"] = 'O';
  output["111"] = 'P';
  output["10011111"] = 'Q';
  output["1000"] = 'R';
  output["00110"] = 'S';
  output["00111"] = 'T';
  output["10011100"] = 'U';
  output["10011101"] = 'V';
  output["000010"] = 'W';
  output["10010010"] = 'X';
  output["10010011"] = 'Y';
  output["10010000"] = 'Z';

  for( int i = 0 ; i < 26 ; i++ ){
    input['A' + i ] = compute(i);
  }
  // 表 A ~ Z は２進数表示
  input[' '] = "11010";
  input['.'] = "11011";
  input[','] = "11100";
  input['-'] = "11101";
  input['\''] = "11110";
  input['?'] = "11111";

  string s;
  while( getline(cin , s) ){
    string c = "";
    // 文字を１と０に変換
    for( int i = 0 ; i < s.size() ; i++ ){
      c += input[s[i]];
    }

    // １文字どとに繋げていって、一致したら
    // tempをリセットし、ansにoutputを付け加える
    
    string temp = "", ans = "";
    for( int i = 0 ; i < c.size() ; i++ ){
      temp += c[i];
      if( output[temp] ){ // outputがあるのか１文字ごとに確認
	ans += output[temp];
	temp = "";
      }
    }
    cout << ans << endl;
  }
  return 0;
}