#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

int main(){
  ll n;cin>>n;
  vector<ll>a(n);
  rep(i, n)cin>>a[i];

  vector<ll>results;
  rep(i, n){
    auto it = lower_bound(results.begin(), results.end(), a[i]);

    if(it!=results.begin()) *prev(it)=a[i];
    else results.insert(it, a[i]);

//cout<<results.size()<<':';rep(i, results.size())cout<<results[i]<<' ';cout<<endl;

  }
  cout<<results.size()<<endl;

  return 0;
}