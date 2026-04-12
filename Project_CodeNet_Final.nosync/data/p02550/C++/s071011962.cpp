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
  l.push_back(c);
  map<int, int>mm;
  mm[c]++;

  rep(i, 100000*4){
    c = c*c%m;
    l.push_back(c);
    mm[c]++;
  }

  if(n<400000){
    ll result = 0;
    rep(i, n)result += l[i];
    cout<<result<<endl;

    return 0;
  }


  ll loop_len = 0;
  ll loop_sum=0;
  for(auto p:mm)if(p.second>1){
    loop_len++;
    loop_sum += p.first;
  }

  ll first_len=0;
  ll first_sum=0;
  for(auto p:mm)if(p.second==1){
    first_len++;
    first_sum += p.first;
  }

  vector<ll>loop;
  rep(i, m*4){
    if(mm[l[i]]>1)loop.push_back(l[i]);
    if(loop.size()>1 && loop[0]==l[i])break;
  }

  ll result = first_sum;
  n -= first_len;;
  result += n/loop_len*loop_sum;

  n = n%loop_len;
  ll last_sum=0;
  rep(i, n)last_sum += loop[i];

  cout<<result+last_sum<<endl;
  return 0;

  cout<<first_len<<' '<<first_sum<<endl;
  cout<<last_sum<<endl;
  cout<<loop_sum<<' '<<loop_len<<endl;

//cout<<loop.size()<<endl;

  return 0;
}