#include <bits/stdc++.h>
#include <map> // pair
using namespace std;

typedef long long ll;
#define vec vector<int>
#define vecll vector<ll>
#define vpair vector<pair<int, int>>
#define vpairll vector<pair<ll, ll>>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i,n)   for(int i=(int)0; i<(int)n; i++)
#define llrep(i,n)   for(ll i=(ll)0; i<(ll)n; i++)
#define REP(i,m,n) for(int i=(int)m; i<(int)n; i++)
#define all(var)     (var).begin(), (var).end()
#define prt(var)     cout << var << endl
#define prt_dbl(i,var) cout<<fixed<<setprecision(i)<<var<<endl;

int main(){
  string S,ans;
  ans = "Yes";
  cin>>S;
  if(S.at(0)==S.at(1)&&S.at(0)==S.at(2))ans = "No";

  cout<<ans<<endl;
}
