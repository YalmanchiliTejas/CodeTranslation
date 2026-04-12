#include <bits/stdc++.h>
using namespace std;
#define ALL(x) x.begin(),x.end()
//map<key,value>

int main(){
  int n,ans=0;
  cin >> n;
  int h[n];
  for(int i=0;i<n;i++)cin >> h[i];
  for(int i=0;i<n;i++){
    int c=0;
    for(int j=0;j<i;j++){
      if(h[j]>h[i])goto gh;
    }
    ans++;
    gh:;
  }
  cout << ans;
}
