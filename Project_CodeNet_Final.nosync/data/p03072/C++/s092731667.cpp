#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

int main(){
  int n,f=0;
  cin >> n;
  int a[n], ans=1;
  for(int i=0;i<n;i++)
    cin >> a[i];
  for(int i=0;i<n;i++){
    for(int j=0;j<i;j++){
      if(a[j]<=a[i])
        f=1;
      else{ 
        f=0;
        break;
      }  
    }
    if(f)
      ans++;
  }
  cout << ans << endl;
  return 0;  
}
