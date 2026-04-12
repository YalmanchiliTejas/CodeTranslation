#include <bits/stdc++.h>
using namespace std;
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define brep(index,num) for(int index=num-1;index>=0;index--)
#define brep1(index,num) for(int index=num;index>0;index--)
#define prin(a) cout<<a<<"\n"
#define kaigyo cout<<"\n"
#define mp(a1,a2) make_pair(a1,a2)
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
#define SORT(V) sort(ALL(V))
#define REV(V) reverse(ALL(V))
#define RSORT(V) SORT(V);REV(V)

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<string> vst;
typedef vector<char> vc;
typedef vector<long double> vd;
typedef vector<pint> vpint;
typedef vector<pll> vpll;
typedef vector<vector<int>> vint2;
ll mod=1e9+7;

const double pi=acos(-1.0);
const ll inf=1LL<<60;
ll gcd(ll p,ll q){if(q==0)return p;return gcd(q,p%q);}  
ll lcm(ll p,ll q){return (p*q)/gcd(p,q);}
ll kaizyo(ll k){ll sum=1;rep1(i,k){sum*=i;sum%=mod;}return sum;}
ll ncr(ll n,ll r){return kaizyo(n)/(kaizyo(r)*kaizyo(n-r));}


int main(){
ios_base::sync_with_stdio(false);cin.tie(NULL);
cout.precision(20);

  int x;cin>>x;
  cout<<((x>=30)?"Yes":"No");


}

