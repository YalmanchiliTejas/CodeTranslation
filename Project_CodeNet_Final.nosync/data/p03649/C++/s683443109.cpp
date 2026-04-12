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
#define DBG_N(hoge) cerr<<"!"<<" "<<(hoge)<<endl;
#define DBG cerr<<"!"<<endl;
#define BITLE(n) (1LL<<((ll)n))
#define BITCNT(n) (__builtin_popcountll(n))
#define SUBS(s,f,t) ((s).substr((f)-1,(t)-(f)+1))
#define ALL(a) (a).begin(),(a).end()
using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;cin>>n;
  priority_queue<ll>que;
  for(int i=0;i<n;i++){
    ll a;cin>>a;
    que.push(a);
  }
  ll ans=0;
  while(que.top()+ans>=n){
    ll num=que.top()+ans;
    que.pop();
    ll cnt=num/n;
    //cout<<cnt<<endl;
    que.push((num-(num/n)*n)-ans-cnt);
    ans+=cnt;
  }
  cout<<ans<<endl;
  return 0;
}
