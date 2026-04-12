#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
typedef pair<int,int> P;

const int MOD=1000000007;
int INF=100100100100100;

signed main(){
  int x,y,z;
  cin>>x>>y>>z;
  int i=0;
  while(y*(i+1)+z*(i+2)<=x){
    i++;
  }
  cout<<i<<endl;
  return 0;
}