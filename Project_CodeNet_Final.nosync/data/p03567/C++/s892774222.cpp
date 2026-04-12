#include<bits/stdc++.h>
typedef long long ll;
#define REP(i,n) for(int i = 0;i < (n);i++)
using namespace std;
const int INF = 1e9;

string s;
int main(){
  cin>>s;
  for(int i=0;i<s.size()-1;i++){
    if(s[i]=='A' && s[i+1]=='C'){cout<<"Yes"<<endl;return 0;}
  }
  cout<<"No"<<endl;
  return 0;
}