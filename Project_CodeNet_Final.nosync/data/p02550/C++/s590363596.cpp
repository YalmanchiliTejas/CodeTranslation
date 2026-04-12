#include <bits/stdc++.h>

using namespace std;
using Graph = vector<vector<int>>;
using Grid= vector<vector<char>>;
using vin= vector<int>;
using ll=long long;
using vll= vector<ll>;
using vbl=vector<bool>;
using vch=vector<char>;
using pnn=pair<int ,int>;

#define ft first
#define sd second
#define fn front
#define pb push_back
#define it insert
#define si(v) int((v).size())
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rell(i,n) for (ll i=0; i< (ll)(n); i++)
#define sot(x) sort(x.begin(), x.end())
#define rese(x) reverse(x.begin(), x.end())
#define vnn(x,y,s,name) vector<vector<int>> name(x, vector<int>(y,s))
#define mse(x) memset(x, 0, sizeof(x))
#define mii(x,y,z) min(x,min(y,z))
#define maa(x,y,z) max(x,max(y,z))

string yes="Yes",no="No";

int main() {
  ll n,x,m;
  cin>>n>>x>>m;
  queue<ll> q;
  set<ll> s;
  ll now=x;
  ll cnt=0;
  ll ans=0;
  q.push(now);
  s.it(now);
  rep(i,100+m){
      now=now*now;
      now%=m;
      if(s.count(now)) break;
      q.push(now);
      s.it(now);
  }
  
  while(!q.empty()){
      ll j=q.front();
      if(j!=now){
          q.pop();
          cnt++;
          ans+=j;
          if(n==cnt){
              cout<<ans<<endl;
              return 0;
          }
          continue;
      }
      
      else {
          ll si=(n-cnt)%(q.size());
          ll roop=(n-cnt)/(q.size());
          int i=0;
          while(!q.empty()){
              if(i<si) ans+=q.front()*(roop+1);
              else ans+=q.front()*roop;
              q.pop();
              i++;
         
          }   
          cout<<ans<<endl;
          return 0;
      }
  }
}   
   

