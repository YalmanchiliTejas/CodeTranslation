#include <bits/stdc++.h>

using namespace std;

int main(){
	int a,b,c,x,y;
	cin >> a >> b >> c >> x >> y;
	long long int ans1 = 0;
	long long int ans2 = 0;
	int z=0;
	ans1 = max(x,y)*c*2;
	if((a+b)/2 >= c){
		z = min(x,y);
		x -= z;
		y -= z;
		ans2 += c*z*2;
	}
	ans2 += a*x;
	ans2 += b*y;
	cout << min(ans1,ans2) << endl;
	
	return 0;
}