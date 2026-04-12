#include<iostream>
#include<string>
using namespace std;

int main(){
  while(1){
    string s;
    int count=0;
    cin >> s;
    int judge[10000]={};
    for(int i=0;i<s.size();i++){
      if((s[i]=='q')||(s[i]=='w')||(s[i]=='e')||(s[i]=='r')||(s[i]=='t')||(s[i]=='a')||(s[i]=='s')||(s[i]=='d')||(s[i]=='f')||(s[i]=='g')||(s[i]=='z')||(s[i]=='x')||(s[i]=='c')||(s[i]=='v')||(s[i]=='b'))judge[i]=0;
      else judge[i]=1;
      if((1<=i)&&(judge[i-1]!=judge[i])) count++;
    }
    if(s[0]=='#')break;
    cout << count << endl;

  }
}