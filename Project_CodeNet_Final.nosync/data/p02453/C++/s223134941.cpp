#include<iostream>
#include<vector>
#include<bitset>
#include<string>
#include<cmath>
#include<algorithm>
#include<stack>
#include<list>
#include<queue>
#include<map>
using namespace std;
#define rep(i,x) for(int i=0;i<x;i++)
#define re(i,x,y) for(int i=x;i<y;i++)
int INF=1e9;
const long long mod=1e9+7;
typedef long long ll;

int main(){
  int n; cin>>n;
  vector<ll>a(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  int q; cin>>q;
  vector<int>k(q);
  for(int i=0;i<q;i++){
    cin>>k[i];
  }
  for(int i=0;i<q;i++){
    cout<<lower_bound(a.begin(),a.end(),k[i])-a.begin()<<endl;
  }
  return 0;
}
