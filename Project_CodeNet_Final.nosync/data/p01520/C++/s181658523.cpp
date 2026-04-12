#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,t,e;
  cin >> n >> t >> e;
  int res = -1;
  for(int i=0;i<n;i++){
    int x, k = 1; cin >> x;
    while(k*x<=t+e){
      if(t-e <= k*x && k*x <= t+e){
	res = i+1;
      }
      k++;
    }
  }
  cout << res << endl;
}