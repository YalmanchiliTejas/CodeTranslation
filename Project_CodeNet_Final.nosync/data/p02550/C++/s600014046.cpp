#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 998244353LL
#define INF 1000000000000000LL

using namespace std;

int main(){
  ll n,x,m;cin>>n>>x>>m;
  if(x==0){cout<<0<<endl; return 0;}

  vector<ll>l;
  ll c = x;
  map<int, int>mm;

  rep(i, 100000*4){
    mm[c]++;
    l.push_back(c);
    c = c*c%m;
  }

  if(n<=100000){
    ll result = 0;
    rep(i, n)result += l[i];
    cout<<result<<endl;

    return 0;
  }


  int loop_len = 0;
  ll loop_sum=0;
  for(auto p:mm)if(p.second>2){
    loop_len++;
    loop_sum += p.first;
  }
  int first_amari=0;
  ll first_sum=0;
  rep(i, m)if(mm[l[i]]==1){
    first_amari++;
    first_sum += l[i];
  }

  vector<ll>loop;
  rep(i, m*4){
    if(mm[l[i]]>1)loop.push_back(l[i]);
    if(loop.size()>1 && loop[0]==l[i])break;
  }

  ll result = first_sum;
  n -= first_amari;
  result += n/loop_len*loop_sum;
  n%=loop_len;
  rep(i, n)result += loop[i];

  cout<<result<<endl;

  return 0;
}
