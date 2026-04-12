#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define MAX 200003
#define MOD 1000000007
using Graph=vector<vector<int>>;

int main(){
  int N;
  cin>>N;
  vector<ll> a(N);
  for(int i=0;i<N;i++){
    cin>>a.at(i);
  }

  if(N%2==1){
    vector<vector<ll>> dp(N,vector<ll>(N,0));
    for(int i=0;i<N;i++){
      dp.at(i).at(i)=a.at(i);
    }
    for(int w=1;w<N;w++){
      for(int i=0;i+w<N;i++){
        if(w%2==1){
          dp.at(i).at(i+w)=min<ll>(dp.at(i).at(i+w-1)-a.at(i+w),dp.at(i+1).at(i+w)-a.at(i));
        }else{
          dp.at(i).at(i+w)=max<ll>(dp.at(i).at(i+w-1)+a.at(i+w),dp.at(i+1).at(i+w)+a.at(i));
        }
      }
    }
    cout<<dp.at(0).at(N-1)<<endl;
  }else{
    vector<vector<ll>> dp(N,vector<ll>(N,0));
    for(int i=0;i<N;i++){
      dp.at(i).at(i)=-a.at(i);
    }
    for(int w=1;w<N;w++){
      for(int i=0;i+w<N;i++){
        if(w%2==1){
          dp.at(i).at(i+w)=max<ll>(dp.at(i).at(i+w-1)+a.at(i+w),dp.at(i+1).at(i+w)+a.at(i));
        }else{
          dp.at(i).at(i+w)=min<ll>(dp.at(i).at(i+w-1)-a.at(i+w),dp.at(i+1).at(i+w)-a.at(i));
        }
      }
    }
    cout<<dp.at(0).at(N-1)<<endl;
  }
}
