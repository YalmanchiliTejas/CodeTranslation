#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> mp;
ll inf =  1e9;


int main(){
 ll n,m,k;
 cin>>n>>m>>k;
 vector<ll> d(m);
 vector<ll> rev(n,-1);
 for(ll i=0;i<m;i++)cin>>d[i],d[i]--,rev[d[i]] = i;
 vector< vector<ll> > v(n,vector<ll>(k,0) );
 set<ll> dd;
 for(ll i=0;i<n;i++){
  for(ll j=0;j<k;j++) cin>>v[i][j],v[i][j]--;
 }
 vector<ll> dp( 1<<m , inf );
 dp[ (1<<m)-1 ] = 0;
 queue<mp> q;
 q.push(  mp( (1<<m)-1 , 0 ) );
 while(!q.empty() ){
  mp now = q.front();
  q.pop();
 // if( dp[now.first] != inf ) continue;
  //dp[nn] = cost;
  ll nn = now.first;
  if( nn == 0 ) break;
  ll cost = now.second;
  for(ll i=0;i<k;i++){
   ll next = 0;
   for(ll j=0;j<m;j++){
    if( (nn>>j)&1 ){
     if( rev[ v[ d[j] ][i] ] != -1 ){
      next |= 1<<rev[ v[d[j]][i] ];
     }
    }
   }

   if( dp[next] != inf ) continue;
   dp[next] = cost + 1;
   q.push( mp( next , cost+1) );
  }
 }
 cout<<dp[0]<<endl;

    return 0;
}

