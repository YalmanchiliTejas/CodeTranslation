#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = a;i < b;i++)
#define rrep(i,a,b) for(int i = a;i >= b;i--)
#define all(x) (x).begin(),(x).end()
#define dbg(x) cerr << #x << ": " << x << endl;
typedef long long ll;
using namespace std;

int main(){
   cin.tie(0);
   ios::sync_with_stdio(false);

   int n,ans = 0,max = -100;
   cin >> n;
   int h[n];
   rep(i,0,n){
      cin >> h[i];
   }
   rep(i,0,n){
      if(h[i] >= max){
         ans++;
         max = h[i];
      }
   }

   cout << ans << endl;

   return 0;
}