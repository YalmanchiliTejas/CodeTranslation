#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i = 0;i<((ll)(n));i++)
#define reg(i,a,b) for(ll i = ((ll)(a));i<=((ll)(b));i++)
#define irep(i,n) for(ll i = ((ll)(n)-1);i>=0;i--)
#define ireg(i,a,b) for(ll i = ((ll)(b));i>=((ll)(a));i--)

/*
同じ色なら単調増加
色の数を決め打つ
a[i]未満の一番大きいところに入れるのが最適

6
1 2 3 3 4 5
*/

ll n,a[100010],cnt=0,lis[100010];

void init(){
	cin>>n;
	rep(i,n)cin>>a[i];
	rep(i,n)lis[i]=-1e18;
}

int main(void){
	init();
	lis[0]=a[0];
	cnt=1;
	reg(i,1,n-1){
		// cerr<<i<<": ";
		// rep(j,cnt)cerr<<lis[j]<<" ";
		// cerr<<endl;
		ll l=cnt-1,r=0;
		if(lis[l]>=a[i]){
			lis[cnt]=a[i];
			cnt++;
			continue;
		}
		if(lis[r]<a[i]){  // これいる？
			lis[r]=a[i];
			continue;
		}
		while(l-r>1){
			ll mid=(l+r)/2;
			if(lis[mid]>=a[i]){
				r=mid;
			}else{
				l=mid;
			}
		}
		lis[l]=a[i];
	}
	// cerr<<n<<": ";
	// rep(i,cnt)cerr<<lis[i]<<" ";
	// cerr<<endl;
	cout<<cnt<<endl;
	return 0;
}