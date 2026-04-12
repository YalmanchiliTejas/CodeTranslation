#include <bits/stdc++.h>
using namespace std;


int main() {

  int64_t a,b,c,x,y;
  cin>>a>>b>>c>>x>>y;

  //4パターン計算して一番安いものが答え
  //A,Bで買った場合
    int64_t money1 = a*x+b*y;
  //Cで買った場合
    int64_t money2 = max(x,y)*2*c;
  //A,B+Cで買った場合
    int64_t money3 = min(x,y)*2*c;
    if(max(x,y)==x){
      money3+=(x-y)*a;
    }else{
      money3+=(y-x)*b;
    }

  cout<<min(money1,min(money2,money3));

  return 0;
}

