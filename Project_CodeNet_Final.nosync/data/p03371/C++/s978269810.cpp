#include <bits/stdc++.h>
#include <math.h>
#include <vector>
#include <queue>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep_1 (i,j,n) for(int i=j;i<n;i++)
typedef long long ll;
typedef long l;
const ll l_INF = 1010101010101010;
const int INF = 1010101010;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

int main(){
  int a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;
  int max_num=max(x,y);
  ll ans=INF;
  rep(i,max_num+1){
    ll sum=0;
    int num_a,num_b;
    if(x-i>0)num_a=x-i;
    else num_a=0;
    if(y-i>0)num_b=y-i;
    else num_b=0;
    sum=c*i*2+a*num_a+b*num_b;
    ans=min(ans,sum);
  }
  cout<<ans;
}
