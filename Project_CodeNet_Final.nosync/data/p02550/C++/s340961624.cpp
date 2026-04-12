#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) begin(x), end(x)
#define chmax(x,y) x = max(x,y)
#define chmin(x,y) x = min(x,y)
using namespace std;
typedef long long ll;
typedef pair <int,int> P;

ll sums[100005],when[100005];

int main(){
  ll n,x,m;
  cin>>n>>x>>m;
  ll now,cnt=0,sum=0;
  while(cnt<n){
    if(cnt==0) now=x;
    else{
      now=now*now;
      now%=m;
    }
    sum+=now;
    cnt++;
    if(when[now]!=0){
      ll shuuki=cnt-when[now];
      ll r=(n-cnt)/shuuki;
      bool f=((n-cnt)%shuuki!=0);
      sum+=r*(sum-sums[when[now]]);
      cnt+=shuuki*r;
      break;
    }
    when[now]=cnt;
    sums[cnt]=sum;
  }
  while(cnt<n){
    now=now*now;
    now%=m;
    sum+=now;
    cnt++;
  }
  cout<<sum<<endl;
  return 0;
}
