#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;cin >> n;
      int maxx = 0;
      int ans = 0;
      for(int i = 0;i < n;i++){
            int t;cin >> t;
            if(t >= maxx){
                  ans++;
                  maxx = t;
            }
      }
      cout << ans;
}