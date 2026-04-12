#include<bits/stdc++.h>
#define FOR(i,n) for(int i=0;i<n;i++)
#define SFOR(i,a,b) for(int i=a;i<b;i++)
#define F first
#define S second
#define INF INT_MAX
#define endl '\n'
using namespace std;
typedef long long ll;
typedef pair<int,int>P;
int main(){
   cin.tie(0);
   ios::sync_with_stdio(false);
   int maxi=-1,ans=0,n,d[21];
   cin>>n;
   FOR(i,n){
     cin>>d[i];
     if(d[i]>=maxi){
      ans++;
     }
     maxi=max(d[i],maxi);
   }
   cout<<ans<<endl;
   return 0;
}
