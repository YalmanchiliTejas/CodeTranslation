#include<bits/stdc++.h>
using namespace std;
using Int = long long;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

//INSERT ABOVE HERE
signed main(){
  int n;
  string s;
  int k;
  cin>>n>>s>>k;
  k--;
  for(int i=0;i<n;i++)
    if(s[i]!=s[k]) s[i]='*';
  cout<<s<<endl;
  return 0;
}
