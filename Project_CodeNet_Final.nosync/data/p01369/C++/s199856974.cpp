#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int getTypedZone(char c){
  if(c=='q' || c=='w' || c=='e' || c=='r' || c=='t' || c=='a' || c=='s' || c=='d' || c=='f' || c=='g' || c=='z' || c=='x' || c=='c' || c=='v' || c=='b'){
    return 0;
  } else {
    return 1;
  }
}

int getChangeNum(string str){
  int last = getTypedZone(str[0]);
  int now,cnt=0;
  for(int i=1;i<str.size(); i++){
    now = getTypedZone(str[i]);
    if(now != last){
      cnt++;
    }
    last = now;
  }
  return cnt;
}

int main(){

  while(1){
    string str;
    cin >> str;
    if(str.compare("#")==0) break;
    cout << getChangeNum(str) << endl;
  }
  return 0;
}