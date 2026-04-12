#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define sz(x) int (x.size());
//typedef pair<int,int> P;

using namespace std;
const int MOD=1000000007;
const int INF=1001001001;


int main(){
  string s;
  cin>>s;
  string ans="No";
  char c=s[0];
  if (s[1]!=s[0])ans="Yes";
  if (s[2]!=s[0])ans="Yes";
  if (s[1]!=s[2])ans="Yes";
cout<<ans;


}
