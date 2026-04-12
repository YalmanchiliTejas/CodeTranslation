#include<iostream>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<utility>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_set>
#include<unordered_map>
#include<bitset>
using namespace std;
#define INF 2147483647
#define LINF 9223372036854775807
#define MOD 1000000007
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
#define repb(i,n) for(int i=n-1;i>=0;i--)
#define MODE 1
#ifdef MODE
#define DEB(X) cout<< #X <<": "<<X<<" ";
#define ARDEB(i,X) cout<< #X <<"["<<i<<"]: "<<X[i]<<" ";
#define END cout<<endl;
#else
#define DEB(X) {}
#define ARDEB(i,X) {}
#define END {}
#endif
//typedef long long int ll;
 

signed main(){
   
   int n,h[111111];
   cin>>n;
   int max=0,ans=0;
   rep(i,n){
   		cin>>h[i];
   		if(max<=h[i])ans++;
   		max=std::max(max,h[i]);
   }
   cout<<ans<<endl;
   
   
}
