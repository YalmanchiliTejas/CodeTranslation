#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;

int main(){
	int a,b,c,x,y;
	cin >> a >> b >> c >> x >> y;
	int ans = 0;
	ans = a*x + b*y;
	//cout << ans << endl;
	ans = min(ans,c*max(x,y)*2);
	//cout << ans << endl;
	int ans2;
	if(min(x,y) == x) ans2 = min(x,y)*c*2 + abs(x-y)*b;
	if(min(x,y) == y) ans2 = min(x,y)*c*2 + abs(x-y)*a;
	ans = min(ans,ans2);
	cout << ans << endl;
}
