#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<string>
#include<algorithm>
#include<utility>
#include<math.h>
#include<cstdlib>
#define rep(i, n) for(int i=0;i<n;i++)
#define repb(i, a, b) for(int i=a;i<b;i++)

using namespace std;
typedef pair<int, int> P;
typedef long long int ll;

const int INF = 1<<30;

ll func(ll level, ll num){
  // cout<<level<<" "<<num<<endl;
  if(level==0LL)return num;
  if(num<=1LL)return 0LL;
  ll l_burger=ll(pow(2, level+1LL))-1LL;
  if(l_burger<=num){
    return ll(pow(2, level)-1LL)+func(level-1LL, min(l_burger-2LL, num-l_burger))+1LL;
  }else{
    if(num<=1) return 0LL;
  	return func(level-1LL, num-1LL);
  }
}

int main(){
  ll n, x;cin>>n>>x;
  cout<<func(n, x)<<endl;
  // system("read -n 1 -s -p \"Press any key to continue...\"");
}
