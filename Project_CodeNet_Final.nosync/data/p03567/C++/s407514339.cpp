#include <bits/stdc++.h>
using namespace std;
//char型から数値型に変換する関数（z.at(i)などに使用）
int ctoi(char c){if(c>='0'&&c<='9'){return c-'0';}return 0;}
int main() {
  string s;
  cin>>s;
  bool t=false;
  for(int i=0;i<s.size()-1;i++){
   if(s.at(i)=='A'&&s.at(i+1)=='C'){
     t=true;
   }
  }
  if(t){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}
