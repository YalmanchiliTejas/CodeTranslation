#include<bits/stdc++.h>
using namespace std;
long long x[1000010],y[1000010];
#define int long long
signed main(){
  
  cin.tie(0);
  ios::sync_with_stdio(false);

  string s;
  cin>>s;
  
  if(s=="a" || s=="i" || s=="u" || s=="e" || s=="o") cout<<"vowel"<<'\n';
  else cout<<"consonant"<<'\n';
} 
