#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i ,n) for(int i = 0; i < (int)(n); i++)

int main(){
  ll A,B,C,X,Y;
  cin >> A >> B >> C >> X >> Y;
  
  ll total_num = X + Y;
  ll total_yen = 0;
  C = C*2;
  if(A+B < C){
    total_yen += (A+B)*min(X,Y);
  }else{
    total_yen += C*min(X,Y);
  }
  
  total_num -= min(X,Y)*2;
  if(X > Y){
    if(A < C){
      total_yen += A*total_num;
    }else{
      total_yen += C*total_num;
    }
  }else{
    if(B < C){
      total_yen += B*total_num;
    }else{
      total_yen += C*total_num;
    }
  }
  
  cout << total_yen << endl;
  
}