#include <bits/stdc++.h>
using namespace std;
int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);
int r,g,b;
cin>>r>>g>>b;
int m=r*100+g*10+b;
if(m%4==0)cout<<"YES";
else cout<<"NO";
  return 0;
}
