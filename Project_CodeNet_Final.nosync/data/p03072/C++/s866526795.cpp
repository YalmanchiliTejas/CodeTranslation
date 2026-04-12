#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,ans = 0,maxi = 0;
  cin >> n;
  vector<int> a(n);
  for(int i = 0;i < n;i++){
    cin >> a[i];
  }
  
  for(int i = 0;i < n;i++){
    if(maxi <= a[i]){
      maxi = a[i];
      ans++;
    }
  }
  cout << ans << endl;
}