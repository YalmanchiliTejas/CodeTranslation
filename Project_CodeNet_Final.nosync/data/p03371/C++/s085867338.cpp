#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define ALL(a)  (a).begin(),(a).end()
#define spa << " " <<
#define MP make_pair
ll MOD = 1e9+7;
//ll MOD = 998244353;
ll INF = 1e18;
void chmin(ll &a, ll b) { if (a > b) a = b; }
void chmax(ll &a, ll b) { if (a < b) a = b; }
void answer1(bool x){
  if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void answer2(bool x){
  if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void answer3(bool x){
  if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
void answer(bool x, ll y, ll z){
  if(x) cout<<y<<endl;else cout<<z<<endl;}   


int main(){
  ll i, j;
  //ll n,x;
  //cin >> n >> x;
  ll a, b, c,x,y;
  cin >> a >> b>>c>>x>>y;
  //string s; cin >> s;
  ll result =0;
  if(x<=y)
    result=min({x*2*c+(y-x)*b,a*x+y*b,y*2*c});
  else
    result=min({y*2*c+(x-y)*a,a*x+y*b,x*2*c});
  
  cout<<result<<endl;
  return 0;
}