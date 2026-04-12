#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define pb push_back
#define sz(x) ((int)(x).size())
#define all(x) x.begin(),x.end()
#define dmp(x) cerr<<#x<<":"<<x<<endl
#define FOR(i,a,b) for(int i=(int)a,c=(int)b;i<c;++i)
#define rep(i,b) FOR(i,0,b)
#define ROF(i,a,b) for(int i=b-1,c=(int)a;i>=c;--i)
#define per(i,b) ROF(i,0,b)
typedef pair<int,int> P;
typedef pair<int,P> PP; 
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
const int MOD = 1e9+7;

signed main(){
  int n;
  cin>>n;
  vector<int> s(n);
  rep(i,n)cin>>s[i];
  int ans=0;
  FOR(i,1,n){
    int f=0;
    set<int> used;
    used.insert(0);
    used.insert(n-1);
    FOR(k,1,n){
	 if(i*k>=n-1)break;
	 int l=k*i,r=n-1-k*i;
	 if(used.count(l)||used.count(r))break;
	 if(l==r)break;
	 if(r<i)break;
	 used.insert(l);
	 used.insert(r);
	 f=f+s[l]+s[r];
	 chmax(ans,f);
    }
  }
  cout<<ans<<endl;
  return 0;
}
