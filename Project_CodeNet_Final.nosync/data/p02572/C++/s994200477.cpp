#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ld long double
#define endl '\n'
#define pb push_back
const int N=1e5+1;
const int INF=1e9+7;

int32_t main()
{
 ios_base::sync_with_stdio(0);
 cin.tie(0); cout.tie(0);
 int n; cin>>n; int A[n];
 for(int i=0;i<n;i++){cin>>A[i];} int ans=0; int x=1;
 int p[n]; p[0]=A[0];
 for(int i=1;i<n;i++)
 {
     p[i]=(A[i]+p[i-1])%INF;
 }
 for(int i=1;i<n;i++)
 {
     ans+=(A[i]*p[i-1]);
     ans%=INF;
 }
 cout<<ans<<endl;
}
