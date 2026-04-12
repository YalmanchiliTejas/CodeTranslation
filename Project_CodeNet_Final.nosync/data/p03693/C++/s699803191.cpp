#include<bits/stdc++.h>
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#define invrep(i,n) for(int64_t i=n-1;i >= 0;i--)
using namespace std;

int main(){
  int r,g,b;
  cin >> r >> g >> b;
  if((g*10+b)%4 == 0){
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}