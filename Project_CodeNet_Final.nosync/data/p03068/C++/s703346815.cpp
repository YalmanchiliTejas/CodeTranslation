#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef  vector<int> vi ;
typedef  vector<string> vs ;
typedef  vector<long long> vl ;
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rep(i,n) FOR(i,0,n)
int main()
{
  int n,k;
  string s;
  cin>>n>>s>>k;
  rep(i,n)
  {
    if(s[k-1] !=s[i])
      cout<<"*";
    else
      cout<<s[i];
  }
  return 0;  
}
