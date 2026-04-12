#include<iostream>
#include<cmath>
#include<numeric>
#include<string>
#include<algorithm>
#include<vector>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<n;i++)
#define int64 long long
#define yokuwaruprime (10*10*10*10*10*10*10*10*10+7)
using namespace std;

int main(){
  int costA,costB,costAB,goalA,goalB;
  cin>>costA>>costB>>costAB>>goalA>>goalB;
  int cand1=costA*goalA+costB*goalB;
  int cand2=2*costAB*max(goalA,goalB);
  int cand3;
  if(goalA>goalB){
    cand3=2*costAB*goalB+(goalA-goalB)*costA;
  }else{
    cand3=2*costAB*goalA+(goalB-goalA)*costB;
  }
  cout<<min(cand1,min(cand2,cand3))<<endl;
}