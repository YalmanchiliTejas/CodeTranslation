#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
#define pb push_back
#define all(v) (v).begin(), (v).end()

int main(){
  int N;
  cin>>N;

  vi dp; //i番目の色で塗っている数字の最大値

  int x;
  for(int i=0; i<N; i++){
    cin>>x;
    auto itr = upper_bound(all(dp), x, [](int a, int b){
      return a > b;
    });
    if(itr!=dp.end()){
      *itr = x;
    }else{
      dp.pb(x);
    }
  }

  cout<<dp.size()<<endl;
}