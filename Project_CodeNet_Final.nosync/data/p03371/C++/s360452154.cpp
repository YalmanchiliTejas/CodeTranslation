#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <vector>

using namespace std;
typedef long long ll;


ll ans,mx,mn=1e8,sum,cnt;
int main(){
	ll a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;
	ll mx = max(x,y);
	ll mn = min(x,y);
	if(mx == x){
		cnt = mn*2*c;
		cnt += a*(x-y);
	} else {
		cnt = mn*2*c;
		cnt += b*(y-x);
	}
	ll second=(a*x)+(b*y);
	ll third = mx*2*c;
	ll p = min(cnt,second);
	ll q = min(p,third);
	cout<<q<<endl;
}
