#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define LL long long
#define N 2050

LL n,k;


int main(){
	cin>>n>>k;
	LL down=0;
	if(k==0){
		cout<<n*n<<endl;
		return 0;
	}
	for(int i=k+1;i<=n;++i){
		LL ri=n/i*i,times=n/i;
		int add=(i-k)*times;
		if(n-ri<k);
		else add+=(n-ri)-k+1;
		down+=add;
	}

	printf("%lld\n",down);
}
