#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MAX 2000000
#define MOD 1000000007
#define INF 10000000000000000

int main(){
  string K;
  int D;
  cin>>K>>D;
  int N=K.size();
  vector<int> a(N);
  for(int i=0;i<N;i++){
    a.at(i)=K.at(i)-'0';
  }

  vector<vector<vector<ll>>> dp(N,vector<vector<ll>>(2,vector<ll>(D,0)));
  for(int i=0;i<a.at(0);i++){
    dp.at(0).at(1).at(i%D)+=1;
  }
  dp.at(0).at(0).at(a.at(0)%D)+=1;
  for(int i=1;i<N;i++){
    for(int j=0;j<D;j++){
      for(int k=0;k<10;k++){
        dp.at(i).at(1).at((j+k)%D)+=dp.at(i-1).at(1).at(j);
      }
      for(int k=0;k<a.at(i);k++){
        dp.at(i).at(1).at((j+k)%D)+=dp.at(i-1).at(0).at(j);
      }
      dp.at(i).at(0).at((j+a.at(i))%D)+=dp.at(i-1).at(0).at(j);
    }
    for(int j=0;j<D;j++){
      dp.at(i).at(1).at(j)%=MOD;
    }
  }

  cout<<(dp.at(N-1).at(0).at(0)+dp.at(N-1).at(1).at(0)-1+MOD)%MOD<<endl;

}
