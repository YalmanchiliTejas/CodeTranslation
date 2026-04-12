#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define ull unsigned long long
#define vi vector<ll>
#define vvi vector<vi>
#define BITLE(n) (1LL<<((ll)n))
#define BITCNT(n) (__builtin_popcountll(n))
#define SUBS(s,f,t) ((s).substr((f)-1,(t)-(f)+1))
#define ALL(a) (a).begin(),(a).end()
using namespace std;
ll cnt[11111][26];
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;cin>>n;

  for(int i=0;i<n;i++){
    string s;cin>>s;
    for(auto a:s)cnt[i][a-'a']++;
  }
  vector<char>ans;
  for(int i=0;i<26;i++){
    ll mi=llINF;
    for(int j=0;j<n;j++){
      mi=min(mi,cnt[j][i]);
    }
    for(int j=0;j<mi;j++)
      ans.pb((char)(i+'a'));
  }
  for(auto a:ans)cout<<a;
  cout<<endl;
  return 0;
}
