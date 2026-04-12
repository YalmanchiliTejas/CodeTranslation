#include <iostream>

using namespace std;

#define ll long long
#define double long double
#define FOR(i,a,b) for(long i = a; i <= b; i++)
#define FOD(i,b,a) for(long i = b; i >= a; i--)

#define DEBUG(x) cerr << #x << " = " << x << endl

#define mod 1000000007

int main(){
	ios_base::sync_with_stdio(0);
	ll r, g, b;
	ll num = 0;
	cin >> r >> g >> b;
	num = r * 100 + g * 10 + b;
	
	if (num % 4== 0) cout << "YES";
	else cout << "NO";
	


	return 0;
}



