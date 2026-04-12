#include <bits/stdc++.h>
#include <iostream>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
 
int main() {
    int n;cin>>n;
    int v;int ans = 1;
    int height;cin >> height;
  
    for(int i=1;i<n;i++){
        int l;cin >> l;
        v=l;
      
        if(v>=height){
            height = v;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

