#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main(){
  string str,cnt;
  string code[32]={"101","000000","000011","10010001","010001","000001","100101","10011010","0101","0001","110","01001","10011011","010000","0111","10011000","0110","00100","10011001","10011110","00101","111","10011111","1000","00110","00111","10011100","10011101","000010","10010010","10010011","10010000"};
  string alph=" ',-.?ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string code2[32]={"00000","00001","00010","00011","00100","00101","00110","00111","01000","01001","01010","01011","01100","01101","01110","01111","10000","10001","10010","10011","10100","10101","10110","10111","11000","11001","11010","11011","11100","11101","11110","11111"};
  string alph2="ABCDEFGHIJKLMNOPQRSTUVWXYZ .,-'?";
  string ans,sub;
  while(getline(cin,str)){
    cnt="",ans="";
    for(int i=0,l=str.size();i<l;i++){
      for(int j=0;j<32;j++){
        if(str[i] == alph2[j]){
          cnt += code2[j];
        }
      }
    }
    int j;
    for(int i=0,l=cnt.size();i<l;i+=code[j].size()){
      for(j=0;j<32;j++){
        if(i+code[j].size()-1>=cnt.size()) continue;
        sub = cnt.substr(i,code[j].size());
        if(sub == code[j]){
          ans += alph[j];
          break;
        }
      }
    }
    cout << ans << endl;
  }
}