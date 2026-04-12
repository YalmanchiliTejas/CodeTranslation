#include<iostream>
#include<climits>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;
const int MAX_VALUE = 100000*5000*2;
int main(){

	int a,b,c,x,y;
	cin >> a >> b >> c >> x >> y;

	int ans = MAX_VALUE;

	int t = max(x,y);
	for(int i = 0; i <= t; i++)
	{
		ans = min(ans, max(0,x-i)*a + max(0,y-i)*b + i*2*c);
	}

	cout << ans << endl;
	
	return 0;
}