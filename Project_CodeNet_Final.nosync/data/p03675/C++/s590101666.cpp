#include<functional>
#include<algorithm>
#include<iostream>
#include<utility>
#include<string>
#include<vector>
#include<cmath>
#include<stack>
#include<queue>
#include<deque>
#include<map>
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,x,n) for(int i=x;i<n;i++)
#define pf push_front
#define pb push_back
#define int long long
using namespace std;
const int INF=1000000007;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

signed main(){
  int n;
  cin>>n;
  int a[200005];
  rep(i,n)cin>>a[i];
  deque<int> dq;
  int x=(n%2==0?0:1);
  loop(i,1,n+1){
    if((i%2==1&&x==1)||(i%2==0&&x==0)){
      dq.pf(a[i-1]);      
    }else{
      dq.pb(a[i-1]);
    }
  }

  rep(i,n){
    cout<<dq[i];
    if(i<n-1)cout<<' ';
  }
  cout<<endl;
  return 0;
}
