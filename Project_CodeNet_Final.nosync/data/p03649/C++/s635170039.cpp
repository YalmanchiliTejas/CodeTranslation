#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define fi first
#define se second
//#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define vi vector<int>
typedef pair<int,int> P;
#define REP(i,x,y) for(int i=x;i<=y;i++)
#define abs(x) ((x)>0?(x):-(x))
#define y1 hhf
#define mp make_pair
const int mod=1e9+7;
const int maxn = 55;
int n;
ll a[maxn];
ll ans;
int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	while(1){
		int id=max_element(a, a+n)-a;
		if(a[id]<n) break;
		for(int i=0;i<n;i++){
			if(i!=id){
				a[i]+=a[id]/n;
			}
		}
		ans += a[id]/n;
		a[id]%=n;
	}
	cout<<ans<<endl;
	return 0;
}