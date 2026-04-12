#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i< (int)(b); ++i)
using namespace std;



int main(){
   cin.tie(0);
   ios::sync_with_stdio(false);
   cout << fixed << setprecision(20);
   
   int n,h[21],ans=0,maxh=0; cin >> n;
   rep(i,0,n) {
   	cin >> h[i];
   	maxh=max(maxh,h[i]);
   	if(h[i]>=maxh) ans++;
   }
   cout << ans << endl;
   
}

