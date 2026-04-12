#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int,ll> P;
typedef pair<P,P> P2;
const ll INF=100000000000000001;
int main() {
	ll n;
	cin>>n;

	ll a[50]={};
	for(int i=0;i<n;++i)cin>>a[i];
	ll k=0;
	bool flg=true;
	while(flg){
		flg=false;
		for(int i=0;i<n;++i){
			if(a[i]>=n){
				flg=true;
				k+=a[i]/n;
				for(int j=0;j<n;++j){
					if(i!=j)a[j]+=a[i]/n;
				}
				a[i]%=n;
			}
		}
	}
	cout<<k<<endl;

	return 0;
}
