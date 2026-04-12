#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
#include<climits>
#include<set>
#include<utility>
using namespace std;
typedef long long int ll;

int main(){

	ll a, b, c, x, y, ans=0;
	cin >> a >> b >> c >> x >> y;
	ll shou=min(x, y);
	if(a+b<2*c){
		ans+=shou*(a+b);
	} else {
		ans+=shou*2*c;
	}
	if(x>y){
		if(a>2*c){
			x-=y;
			ans+=x*2*c;
		} else {
			x-=y;
			ans+=x*a;
		}
	} else {
		if(b>2*c){
			y-=x;
			ans+=y*2*c;
		} else {
			y-=x;
			ans+=y*b;
		}
	}
	cout << ans << endl;

	return 0;
}