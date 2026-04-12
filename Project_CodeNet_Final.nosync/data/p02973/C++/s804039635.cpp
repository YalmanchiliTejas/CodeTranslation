#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
#define pb push_back
#define all(v) (v).begin(), (v).end()
#define debug(x) cout<<#x<<" = "<<(x)<<endl
#define debugv(v) do{for(auto x:(v)) cout<<x<<","; cout<<endl;}while(0)

int main(){
  int N;
  cin>>N;

  vi dp; //i番目の色で塗っている数字の最大値

  int a;
  for(int i=0; i<N; i++){
    cin>>a;
    auto itr = upper_bound(all(dp), a, [](int a, int b){
      return a > b;
    });
    if(itr!=dp.end()){
      *itr = a;
    }else{
      dp.pb(a);
    }
    //debug(dp.size());
    //debugv(dp);
  }

  cout<<dp.size()<<endl;
}