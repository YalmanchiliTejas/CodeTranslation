#define _USE_MATH_DEFINES 
#include <iomanip> 
#include <cmath>  
#include<iostream>
#include <fstream>
#include<vector>
#include<algorithm>
#include<bitset>
#include<map>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define repi(i,a,b) for(ll i = (ll)(a) ; i < (ll)(b) ; i++)
#define repd(i,a,b) for(ll i = (ll)(a) ; i > (ll)(b) ; i--)
#define rd(x) cin >> x
#define wr(x)  cout << x
#define wrln(x) cout << x << endl

int x, y, z;

int main() {
	cin >> x >> y >> z;
	x -= z;
	int a = y + z;
	wrln(x / a);

	return 0;
}