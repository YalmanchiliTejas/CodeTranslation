#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int a[n];
  for(int i=0;i<n;i++)
    cin >> a[i];
  int ans=1, flag=0;
  for(int i=1;i<n;i++){
    for(int j=0;j<i;j++){
      	if(a[j]<=a[i]){
          flag=1;
        }
      else{
      flag=0;
      break;
      }
    }
    if(flag)
      	ans++;
  }
  cout << ans << endl;
  return 0;
}
