#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

int main(){
	long long a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	long long ans=0;

	if(2*c<=a+b){
		ans+=2*c*min(x,y);
		long long left=max(x,y)-min(x,y);

		if(max(x,y)==x){
			if(2*c<=a) ans+=2*c*left;
			else ans+=a*left;
		}else{
			if(2*c<=b) ans+=2*c*left;
			else ans+=b*left;
		}
	}else{
		ans+=x*a+y*b;
	}

	cout<<ans<<endl;

	return 0;
}
