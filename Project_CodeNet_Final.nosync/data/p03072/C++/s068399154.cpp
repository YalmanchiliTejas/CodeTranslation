#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  int a[20];
  cin >> n;
  for(int i=0;i<n;i++){
	cin >> a[i];    
  }
  int max_height = 0;
  int ans = 0;
  for(int i=0;i<n;i++){
    if(max_height <= a[i])
      ans++;
    max_height = max(max_height, a[i]);
  }
  cout << ans << endl;
}