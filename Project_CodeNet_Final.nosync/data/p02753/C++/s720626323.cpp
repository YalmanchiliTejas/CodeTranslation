#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return true;}return false;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return true;}return false;}
const ll INF = 1LL<<60;
const ll M = pow(10,9)+7;
/*template*/

int main()
{
  string s;cin>>s;
  string ans= s[0]==s[1] && s[0]==s[2] ? "No":"Yes";
  cout<<ans<<endl;
  return 0;
}
