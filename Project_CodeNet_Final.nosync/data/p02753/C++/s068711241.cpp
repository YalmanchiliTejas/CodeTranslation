#include <bits/stdc++.h>
#define per(i,a,n) for(int i=a;i<=n;i++)
using namespace std;
typedef long long ll;
typedef vector<ll>vec;
typedef vector<vector<ll>> mat;
set<int>s;
int a[5];
//vector<int>a[5];
int main()
{
  string s;
  cin>>s;
  for(int i=0;i<s.size();i++){
    if(s[i]=='A')a[1]++;
    else  a[2]++;
  }
  if(a[1]&&a[2]) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}

