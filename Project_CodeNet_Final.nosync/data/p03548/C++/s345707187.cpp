#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define CLR(mat) memset(mat, 0, sizeof(mat))
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll x,y,z,a,b;
	cin >> x >> y >> z;
	x=x-2*z;
	a=y+z;
	b=0ll;
	if(x%a>=y){
		b=1ll;
	}
	cout << x/a+b << endl;


	return 0;
}