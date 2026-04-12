#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<char> vchar;
typedef vector<int> vint;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<vector<int>> vvint;
typedef vector<vector<char>> vvchar;
typedef priority_queue<long long> prque;
#define ain(i,n,a) for(long long i=0;i<(long long)(n);i++){cin>>a[i];}
#define aout(i,n,a) for(long long i=0;i<(long long)(n);i++){if(i){cout<<" ";}cout<<a[i];if(i==n-1){cout<<endl;}}
#define rep(i, n) for(long long i = 0; i < (long long)(n); i++)
#define vsort(v) sort((v).begin(), (v).end())
#define vrsort(v) sort((v).rbegin(), (v).rend())
#define vreverse(v) reverse((v).begin(), (v).end())
#define pb(a) push_back(a)
#define INF 2000000009
#define MOD 1000000007
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  //input
  ll n,i;cin>>n;vll a(n);ain(i,n,a);
  //caricurate
  deque<ll> deq;
  vsort(a);rep(i,n){deq.pb(a[i]);}
  deque<ll> ans;vll la(0);
  ll s=deq.front();deq.pop_front();ans.pb(s);
  while(!deq.empty()){
    s=deq.back();deq.pop_back();ans.push_front(s);
    if(!deq.empty()){s=deq.back();deq.pop_back();ans.pb(s);}else{continue;}
    if(!deq.empty()){s=deq.front();deq.pop_front();ans.push_front(s);}else{continue;}
    if(!deq.empty()){s=deq.front();deq.pop_front();ans.pb(s);}
  }
  while(!ans.empty()){
    ll k=ans.front();ans.pop_front();la.pb(k);
  }
  ll ri=0;rep(i,n-1){ri+=abs(la[i+1]-la[i]);}
  
  deque<ll> deqi;
  vrsort(a);rep(i,n){deqi.pb(a[i]);}
  deque<ll> ansi;vll lai(0);
  ll si=deqi.front();deqi.pop_front();ansi.pb(si);
  while(!deqi.empty()){
    si=deqi.back();deqi.pop_back();ansi.push_front(si);
    if(!deqi.empty()){si=deqi.back();deqi.pop_back();ansi.pb(si);}else{continue;}
    if(!deqi.empty()){si=deqi.front();deqi.pop_front();ansi.push_front(si);}else{continue;}
    if(!deqi.empty()){si=deqi.front();deqi.pop_front();ansi.pb(si);}
  }
  while(!ansi.empty()){
    ll ki=ansi.front();ansi.pop_front();lai.pb(ki);
  }
  ll rii=0;rep(i,n-1){rii+=abs(lai[i+1]-lai[i]);}
  //output
  cout<<max(ri,rii)<<endl;
}