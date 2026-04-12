
#include<bits/stdc++.h>
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define MOD 1000000007
using namespace std;
typedef long long ll;

void FAST() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
}

int main()
{

	FAST();
//freopen("input.txt","r",stdin);
//freopen("output.txt","w",stdout);
ll n; cin>>n; ll arr[n]; REP(i,0,n) cin>>arr[i];

ll size2=n-1;
ll sum[size2];
sum[size2-1]=arr[n-1];
ll k=n-2;
for(int i=size2-2;i>=0;i--){
	sum[i]=(sum[i+1]%MOD+arr[k]%MOD)%MOD;
	k--;
}

for(auto i:sum)
	 cerr<<i<<" ";
  
ll finalsum=0;

/*REP(i,0,n){
	finalsum+=(arr[i]%MOD*(sum[i])%MOD)%MOD;
}
*/
REP(i,0,n-1){
	finalsum=((finalsum)%MOD+((arr[i]%MOD*sum[i]%MOD)%MOD)%MOD)%MOD;
}

//cerr<<"sum= "<<finalsum;
cout<<finalsum;
	return 0;
}