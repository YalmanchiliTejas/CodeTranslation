#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <bitset>
#include <complex>
#include <stack>



#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = (int)(n-1); i >= 0; i--)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;cin>>n;
  vector<ll>s(n);
  rep(i,n){
    cin>>s[i];
  }

  s[0]=0;
  s[n-1]=0;
  ll res=s[n-1];
  repi(d,1,n){
    vector<ll>su;
    //cout<<d<<endl;
    if((n-1)%d==0){

      for(int i=0;i<n-1-i;i+=d)su.push_back(s[i]+s[n-1-i]);


      ll l=su.size();
      rep(i,l-1)su[i+1]+=su[i];
      rep(i,l)chmax(res,su[i]);
    }
    else {
      for(int i=0;i<n;i+=d)su.push_back(s[i]+s[n-1-i]);

      ll l=su.size();
      su[l-1]=0;
      rep(i,l-1)su[i+1]+=su[i];
      rep(i,l)chmax(res,su[i]);

    }
  }
  cout<<res<<endl;

  return 0;

}
