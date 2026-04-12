#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
const ll INF = 1LL<<60;

int main()
{
  ll n,m;cin>>n>>m;
  string ans= n==m ? "Yes":"No";
  cout<<ans<<endl;
  return 0;
}
