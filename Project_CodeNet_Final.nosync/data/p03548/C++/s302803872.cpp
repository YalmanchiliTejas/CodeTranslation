#include <bits/stdc++.h>
using namespace std;

int main(){
	int x,y,z;
    cin>>x>>y>>z;
    int p=(x-2*z)%(y+z);
    int ans=(x-2*z)/(y+z);
    if(p>=y) ans++;
    cout<<ans;
}
  