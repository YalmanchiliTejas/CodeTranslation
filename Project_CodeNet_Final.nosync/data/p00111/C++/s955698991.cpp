#include<iostream>
#include<map>
#include<vector>

using namespace std;

const int MAX = 32;
typedef pair<string, char> P;
map<char,string> M;

P data[MAX];

bool same(string a,string b){

  for(int i = 0; i < a.length(); i++)
    if(a[i] != b[i]) return false;

  return true;
}

char find(string s){
  for(int i = 0; i < MAX; i++){
    if(s.length() == data[i].first.length())
      if(same(s,data[i].first)) return data[i].second;
  }

  return '!'; 
}

void solve(string in){

  string out = "";
  string ans = "";
  char c;
  for(int i = 0; i < in.length(); i++)
    out += M[in[i]];

  out += "0";
  for(int i = 0; i < out.length(); ){
    int len = 3;
    while(1){
      string check = "";
      for(int j = 0; j < len; j++){
	check += out[i+j];
      }
      if((c = find(check)) != '!') break;
      len++;

      if(i+len >= out.length()){
	cout << ans << endl;
	return;
      }
    }
    ans += c;
    i+=len;
  }
}

string to_b(int num){
  string out = "";
  for(int i = 4; i >= 0; i--){
    if(num >= (1<<i)){
      out += "1";
      num -= (1<<i);
    }else out += "0";
  }

  return out;
}

void make(){
  data[0].first = "101"; data[0].second = ' ';
  data[1].first = "000000"; data[1].second = '\'';
  data[2].first = "000011"; data[2].second = ',';
  data[3].first = "10010001"; data[3].second = '-';
  data[4].first = "010001"; data[4].second = '.';
  data[5].first = "000001"; data[5].second = '?';
  data[6].first = "100101"; data[6].second = 'A';
  data[7].first = "10011010"; data[7].second = 'B';
  data[8].first = "0101"; data[8].second = 'C';
  data[9].first = "0001"; data[9].second = 'D';
  data[10].first = "110"; data[10].second = 'E';
  data[11].first = "01001"; data[11].second = 'F';
  data[12].first = "10011011"; data[12].second = 'G';
  data[13].first = "010000"; data[13].second = 'H';
  data[14].first = "0111"; data[14].second = 'I';
  data[15].first = "10011000"; data[15].second = 'J';
  data[16].first = "0110"; data[16].second = 'K';
  data[17].first = "00100"; data[17].second = 'L';
  data[18].first = "10011001"; data[18].second = 'M';
  data[19].first = "10011110"; data[19].second = 'N';
  data[20].first = "00101"; data[20].second = 'O';
  data[21].first = "111"; data[21].second = 'P';
  data[22].first = "10011111"; data[22].second = 'Q';
  data[23].first = "1000"; data[23].second = 'R';
  data[24].first = "00110"; data[24].second = 'S';
  data[25].first = "00111"; data[25].second = 'T';
  data[26].first = "10011100"; data[26].second = 'U';
  data[27].first = "10011101"; data[27].second = 'V';
  data[28].first = "000010"; data[28].second = 'W';
  data[29].first = "10010010"; data[29].second = 'X';
  data[30].first = "10010011"; data[30].second = 'Y';
  data[31].first = "10010000"; data[31].second = 'Z';

  for(char c = 'A'; c <= 'Z'; c++)
    M[c] = to_b((int)(c-'A'));
 
  M[' '] = "11010";
  M['.'] = "11011";
  M[','] = "11100";
  M['-'] = "11101";
  M['\''] = "11110";
  M['?'] = "11111";
}


int main(){
  string in;
  make();
  while(getline(cin,in)) solve(in);
  return 0;
}