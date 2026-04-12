#include<bits/stdc++.h>
#define vll vector<ll>
#define vi vector<int>
#define vpll vector<pair<ll,ll>>
#define pii pair<int,int>
#define REP(i,a) for(int (i)=0; (i)<(a); (i)++)
#define REP2(i,a,b) for(int (i)=(a); (i)<(b); (i)++)
#define MOD 1000000007
#define ALL(v) v.begin(), v.end()
#define m0(x) memset(x,0,sizeof(x))
typedef long long ll;

using namespace std;

int gcd(int a,int b){return b?gcd(b,a%b):a;}
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll N;
  cin>>N;
  vll H(N);
  REP(i,N)cin>>H[i];
  ll height=H[0],ans=1;
  REP2(i,1,N){
    if(H[i]>=height)ans++;
    height = max(height,H[i]);
  }
  cout<<ans;
  
  return 0;
}