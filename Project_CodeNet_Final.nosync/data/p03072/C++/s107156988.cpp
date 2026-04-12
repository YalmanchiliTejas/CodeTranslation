#include<iostream>
using namespace std;
int main(){
int n;
  cin >> n;
  int h[n];
  for (int i = 0; i < n; i++)
    cin >> h[i];
  int ans = 1, maxi = h[0];
  for (int i = 1; i< n; i++){
    if(maxi < h[i]+1){
    	maxi = h[i];
      	ans += 1;
    }
  }
  cout << ans <<'\n';
    
	return 0;
}