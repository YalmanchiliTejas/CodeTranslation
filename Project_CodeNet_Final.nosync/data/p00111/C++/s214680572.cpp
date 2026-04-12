#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;

map<string,string> board;
map<string,string> word;

void config(){
  string w = "ABCDEFGHIJKLMNOPQRSTUVWXYZ .,-'?";
  string s = "00000";
  string h[] = {"100101","10011010","0101","0001","110","01001","10011011",
		"010000","0111","10011000","0110","00100","10011001",
		"10011110","00101","111","10011111","1000",
		"00110","00111","10011100","10011101",
		"000010","10010010","10010011","10010000",
		"101","010001","000011","10010001","000000","000001"};
  for(int i=0;i<w.size();i++){
    string tmp = "";
    tmp += w[i];
    board[tmp] = s;
    word[h[i]] = w[i];
    /*
    cout << tmp << " " << s << endl;
    cout << h[i] << " " << w[i] << endl << endl;
    */
    if(s[4] == '0') s[4] = '1';
    else {
      for(int j=4;j>=0;j--){
	if(s[j] == '0'){
	  s[j] = '1';
	  break;
	}
	else s[j] = '0';
      }
    }
  }
}

int main(){
  config();
  string str;
  while(getline(cin,str)){
    string next = "";
    for(int i=0;i<str.size();i++){
      string tmp = "";
      tmp += str[i];
      next += board[tmp];
    }
    string ans = "";
    string now = "";
    for(int i=0;i<next.size();i++){
      now += next[i];
      if(word[now] != word["AA"]){
	ans += word[now];
	now = "";
      }
    }
    cout << ans << endl;
  }
}