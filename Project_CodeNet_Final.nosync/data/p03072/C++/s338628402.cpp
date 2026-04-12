#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0;i<(int)(n);i++)
#define all(x)    (x).begin(),(x).end()
typedef long long ll;
const int MOD = (int)1e9 + 7;

int main(){
  int n;
  cin>>n;
  int ans=0;
  int now_max = 0;
  rep(i,n){
    if (i==0){
      cin>>now_max;
      ans++;
      continue;
    }
    int buf;
    cin>>buf;
    if(now_max<=buf){
      ans++;
      now_max = buf;
    }
  }
  cout<<ans<<endl;
}

