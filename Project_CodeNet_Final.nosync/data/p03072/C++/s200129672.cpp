#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < n; ++i)

using namespace std;

int main(void){
int n,z;
int h = -1;
int ans = 0;

cin >> n;
rep(i,n){
  cin >> z;
  if(h <= z){
    ans++;
    h = max(z, h);
  }
  }
cout << ans << endl;



return 0;
}
