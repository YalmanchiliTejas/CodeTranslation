#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
  int n; cin >> n;
  vector<int> h(n);
  for(int i=0; i<n; i++){
    cin >> h[i];
    }
    int ans=1;
    int a = h[0];
    for(int i=1; i<n; i++){
      a = max(a,h[i]);
      if(a==h[i]){
        ans++;
      }
    }
    cout << ans << endl;
  }
