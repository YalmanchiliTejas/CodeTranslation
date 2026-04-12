#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int A[110];
int main(){
	int a,b,c,x,y;
	cin >>  b >> c >> a >> x >> y;
	int ans1 = x * b + y * c;
	int ans2 = max(x,y) * 2 * a; 
	int ans3 = min(x,y) * 2 * a + b * (x - min(x,y)) + c * (y - min(x,y));
	int ans = min(ans1,ans2);
	ans = min(ans,ans3);
	//cout << ans1 << " " << ans2 << "  " << ans3 << endl;
	cout << ans;
	return 0;
}