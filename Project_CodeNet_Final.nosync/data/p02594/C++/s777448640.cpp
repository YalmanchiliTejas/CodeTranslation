#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()

// #define DEBUG 100

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int oo = 1e9 + 7;
const ll mod = 1e9 + 7,maxn = 100010;
const double PI = acos(-1);

string solve (int n){
	if (n >= 30 ) return "Yes";
	return "No";
}

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;

	cout << solve(n) << endl;
}	

