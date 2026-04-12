#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
vector<int> i;
vector<int> u;
vector<int> o;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long a=0,b,c,d=0,e=0,f=0,g;
  string s;
  cin >>a>>s>>b;
  for(int n=0;n<a;n++){
    if(s[b-1]!=s[n]) s[n]='*';
  }
  cout <<s<<'\n';
  return (0);
}
