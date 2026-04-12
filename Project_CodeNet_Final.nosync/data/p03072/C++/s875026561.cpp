#include "bits/stdc++.h"
using namespace std;
#define pb push_back
#define vi vector<int>
#define fi first
#define se second 
#define mp make_pair
#define show(x) cout<<#x<<" = "<<x<<endl;
typedef unsigned long long ull;
typedef pair<int,int> P;
#define LL long long 
#define pi acos(-1)
#define fin freopen("in","r",stdin);
const int inf=0x3f3f3f3f;
const double eps=1e-8;
#define zero(x) (((x)>0?(x):-(x))<eps)
#define _sign(x) ((x)>eps?1:((x)<-eps?2:0))
typedef long long ll;
const int maxn = 1000005, mod = 1e9+7;
#define fin freopen("in","r",stdin);
int a[maxn],n;
int main(){
	int mx=0,ans=0;
	cin>>n;
	for(int i=0;i<n;i++) {
		cin>>a[i];
		if(a[i]>=mx){
			mx=a[i];
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}