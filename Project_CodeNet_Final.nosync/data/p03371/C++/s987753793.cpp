#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<map>
#include<numeric>
#define rep(i,n) for(int i=0;i<n;++i)
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
#define mod 1000000007
using namespace std;
using ll = long long;
int main() {
	int A, B, C, X, Y;	cin >> A >> B >> C >> X >> Y;
	int AB = 2 * C, price, ans = mod;
	rep(i, 100001) ans = min(ans, AB * i + A * max(0, X - i) + B * max(0, Y - i));
	cout << ans << endl;
	cin >> A;
}
