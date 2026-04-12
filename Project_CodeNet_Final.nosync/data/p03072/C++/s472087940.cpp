#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0 ; i<(n) ; i++)
#define repr(i,n) for(int i=(n) ; i>=0 ; i--)
#define FOR(i,m,n) for(int i=(m) ; i<(n) ; i++)
#define FORR(i,m,n) for(int i=(m) ; i>=(n) ; i--)

#define All(x) (x).begin(),(x).end()

typedef long long ll;
typedef unsigned long long ull;

const int INF = 1e9;

int main(){
   int n;
   cin >> n;
   vector<int> h(n);
   rep(i,n)cin >> h[i];
   int ans = 1;
   for(int i=1;i<n;i++){
      bool flag = true;
      for(int j=0;j<i;j++){
         if(h[j]>h[i]){
            flag = false;
            break;
         }
      }
      if(flag){
         ans++;
      }
   } 
   cout << ans << endl;
   return 0;
}