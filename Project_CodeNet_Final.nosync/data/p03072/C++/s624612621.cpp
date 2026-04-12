#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<utility>
#include<algorithm> // sort
#include<map> // pair
#include<cmath>
using namespace std;
using ll = long long;
const ll mod = 1e9+7;
int main(){
  ll n,maximum=0,x;
  cin >> n;
  ll count = 0;
  for(int i=0;i<n;i++){
    cin >> x;
    if(x >= maximum){
      count ++;
      maximum = x;
    }
  }
  cout << count;
}
