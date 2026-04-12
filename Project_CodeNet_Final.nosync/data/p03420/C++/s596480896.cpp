#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
int main()
{
   ll N,K;
   cin >> N >> K;
   ll ans=0;
   for(ll b=K+1;b<=N;b++){
      ll num = b-K;
      ll lim= N/b;
      ans+=num*lim;
      if(K==0)ans--;
      ans+=max(N-b*lim-(K-1),0ll);
      //cout << b << ":" << lim << endl;
   }
   cout << ans << endl;
   return 0;
}