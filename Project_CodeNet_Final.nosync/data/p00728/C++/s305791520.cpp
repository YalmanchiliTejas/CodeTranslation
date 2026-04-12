#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define endl "\n"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  while(cin>>n){
    if(n==0)return 0;
    vector<int>s(n);
    for(int i=0;i<n;i++)cin>>s[i];
    sort(rng(s));
    int ans=0;
    for(int i=1;i<n-1;i++)ans+=s[i];
    cout<<ans/(n-2)<<endl;
  }
  return 0;
}

