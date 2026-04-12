#include <bits/stdc++.h>
using namespace std;
#define int lint
typedef long long lint;
typedef pair<int,int> P;
const int    INF=(int)1e9;
const int    MOD=(int)1e9+7;
const double EPS=(double)1e-10;
struct Accelerate_Cin{
    Accelerate_Cin(){
        cin.tie(0); ios::sync_with_stdio(0);cout<<fixed<<setprecision(20);
    };
};



signed main(){
  int N;cin>>N;
  int x=N*800;
  int y=(N/15)*200;

  cout<<x-y<<endl;
  return 0;
}
