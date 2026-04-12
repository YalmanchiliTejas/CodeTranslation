#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>
#include <utility>
#include <numeric>
#include <string>
#include <set>
#include <map>
#include <tuple>
#include <queue>
#define rep(i, a, n) for(int i = int(a);i < int(n);++i)
#define repe(i, a, n) for(int i = int(a);i <= int(n);++i)
#define repr(i, a, n) for(int i = int(a);i > int(n);--i)
#define reper(i, a, n) for(int i = int(a);i >= int(n);--i)
#define size(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
#define yes cout << "yes" << endl;
#define no cout << "no" << endl;
#define pb push_back
#define EPS (1e-20)
#define INF 2147483647
using llint = long long;
using VI = std::vector<int>;
using PII = std::pair<int, int>;
using namespace std;


int A, B, C, X, Y;


int solve(){
	int ans = 0;
	C *= 2;
	if(A+B < C){
		if(X < Y){
			ans = A*X+B*X;
			if(B < C) ans += B*(Y-X);
			else ans += C*(Y-X);
		}
		else {
			ans = A*Y+B*Y;
			if (A < C) ans += A*(X-Y);
			else ans += C*(X-Y);
		}
	}
	else {
		if (X < Y){
			ans = C*X;
			if (B < C) ans += B*(Y-X);
			else ans += C*(Y-X);
		}
		else{
			ans = C*Y;
			if (A < C) ans += A*(X-Y);
			else ans += C*(X-Y);
		}
	}
	return ans;
}


int main(){
	cin >> A >> B >> C >> X >> Y;

	cout << solve() << endl;

	return 0;
}