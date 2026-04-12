#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
ll gcd(ll x, ll y) { return (x % y)? gcd(y, x % y): y; }    //最大公約数
ll lcm(ll x, ll y) { return x / gcd(x, y) * y; }     //最小公倍数
using Graph = vector<vector<ll>>;
ll inf=300000000000000000;
const double PI = 3.14159265358979323846;
int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<int>> k(n,vector<int>(n,-1));
  rep(i,m){
    int a,b;
    cin >> a >> b;
    a--;
    b--;
    k[a][b]=1;
    k[b][a]=1;
  }
  int u[n-1];
  int ans=0;
  rep(i,n-1)u[i]=1+i;
  do{
    if(k[0][u[0]]==-1)continue;
    int y=0;
    rep(i,n-2)if(k[u[i]][u[i+1]]==-1)y++;
    if(y==0)ans++;
  }while(next_permutation(u,u+n-1));
  cout << ans << endl;
}   
