// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
signed main(){
  ll x,y,z,len;
  cin >> x >> y >> z;
  for(int i=1;;i++){
    len = y*i+z*(i+1);
    if(len>x){
      cout << i-1<<endl;
      break;
    }else if(len==x){
      cout << i<<endl;
      break;
    }
  }
}
