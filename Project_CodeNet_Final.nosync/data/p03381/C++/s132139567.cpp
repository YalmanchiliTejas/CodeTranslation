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
  vi A(n);
  vi ori;
  for(auto &a:A){cin>>a;ori.pb(a);}
  sort(ALL(A));
  double mid=((double)A[n/2-1]+A[n/2])/2;
  for(auto a:ori){
    //  cout<<a<<" "<<mid<<endl;
    if((double)a<mid){
      cout<<A[n/2]<<endl;
    }else{
      cout<<A[n/2-1]<<endl;
    }
  }
  return 0;
}
