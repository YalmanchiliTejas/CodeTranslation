#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <map>
const int MOD = 1e9+7;
typedef long long ll;
using namespace std;

ll bargar[51];
ll patty[51];

ll get_patty(ll n, ll x){
	if (n == 0) return 1;
	if (x == 1) return 0;
	else if (x <= bargar[n-1]+1) return get_patty(n-1, x-1);
	else if (x == bargar[n-1]+2) return patty[n-1] + 1;
	else if (x <= 2*bargar[n-1]+2) return get_patty(n-1, x-bargar[n-1]-2) + patty[n-1] + 1;
	else return 2*patty[n-1] + 1;
}


int main(){
	ll n, x;
	cin >> n >> x;
	bargar[0] = 1;
	patty[0] = 1;

	for (int i = 1; i <= 50; i++){
		bargar[i] = 3 + 2*bargar[i-1];
		patty[i] = 1 + 2*patty[i-1];
	}

	cout << get_patty(n, x) << endl;
 	return 0;
 }


