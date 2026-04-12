#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define F first
#define S second
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<int,int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll gcd(ll a, ll b) { return b?gcd(b, a%b):a;}
ll lcm(ll a, ll b) { return a*b/gcd(a,b);}
ll MOD=1000000007;

int main(){
  string s;cin>>s;
  if(s=="AAA" or s=="BBB"){
    cout<<"No"<<endl;
  }else{
    cout<<"Yes"<<endl;
  }
}