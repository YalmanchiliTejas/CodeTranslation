#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define BITLE(n) (1LL<<((ll)n))
#define SHIFT_LEFT(n) (1LL<<((ll)n))
#define SUBS(s,f,t) ((s).substr((f),(t)-(f)))
#define ALL(a) (a).begin(),(a).end()
using namespace std;
ll cnt = 0;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll h,w;cin>>h>>w;
  for(int i=0;i<h;i++){
    string s;cin>>s;
    for(auto c:s)cnt += (c == '#');
  }
  if(cnt == h+w-1)cout<<"Possible"<<endl;
  else cout<<"Impossible"<<endl;
  return 0;
}
