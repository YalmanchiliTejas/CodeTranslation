#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define rFOR(i,a,b) for(int i=a;i>=b;i--)
#define rep(i,b) FOR(i,0,b)
#define INF 1e9
#define dump(x) cerr<< #x << " = "<<(x)<<endl
#define int long long

using ll = long long;
const ll mod = LLONG_MAX;

typedef pair<int,int> P;


signed main(){
  int a,b,c;
  cin>>a>>b>>c;
  int r=a*100+b*10+c;
  if(r%4==0){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }

}
