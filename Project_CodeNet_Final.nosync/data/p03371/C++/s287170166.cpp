#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000



int main(){
	
	long long A,B,C,X,Y;
	cin>>A>>B>>C>>X>>Y;
	
	long long ans = Inf;
	
	for(long long i=0;i<=1000000;i+=2){
		int x = X-i/2;
		int y = Y-i/2;
		long long a = i*C;
		
		a += A*max(x,0);
		a += B*max(y,0);
		ans = min(ans,a);
	}
	
	cout<<ans<<endl;
		
    return 0;
}
