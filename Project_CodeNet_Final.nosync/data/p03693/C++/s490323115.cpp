#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin >> a>> b>> c;
  int ans=a*100+b*10+c;
  if(ans%4==0){
    cout << "YES" << "\n";
  }else{
    cout <<"NO" << "\n";
  }
}