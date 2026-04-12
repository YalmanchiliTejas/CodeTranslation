#include <iostream>
#include <cmath>
#include <utility>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
#define mp make_pair
#define x first
#define y second

ll modm[100003];

int main () {
	ll n;
	cin>>n;
	ll m,x;
	cin>>x>>m;
	if(n<m){
		ll s=0ll;
		for(int i=1;i<=n;i++){
			s+=x;
			x=(x*x)%m;
		}
		cout<<s;
		return 0;
	}
	ll br=1,cik,s=0ll,scik=0ll,sost=0ll;
	while(true){
		if(modm[x]==0){
			modm[x]=br;
			s+=x;
		}
		else{
			cik=br-modm[x];
			break;
		}
		br++;
		x=(x*x)%m;
	}
	n-=br-1;
	ll brc=n/cik;
	ll ost=n%cik;
	ll y=x;
	int novibr=0;
	while(true){
		scik+=x;
		novibr++;
		if(novibr==ost){
			sost=scik;
		}
		if((x*x)%m==y) break;
		x=(x*x)%m;
	}
	s+=brc*scik+sost;
	cout<<s;
	



return 0;
}

