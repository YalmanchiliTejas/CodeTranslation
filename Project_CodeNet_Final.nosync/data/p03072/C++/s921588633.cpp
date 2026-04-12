#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int l, i=0, a[n];
    while(cin>>l){
        a[i] = l;
        i++;
    }
  int ans=1;
  int max=a[0];
  for (int k = 1; k < n; ++k) {
  	if(a[k] >= max){
  		ans = ans +1;
      	max = a[k];
    }
  }
  
      cout << ans << endl;
  
}