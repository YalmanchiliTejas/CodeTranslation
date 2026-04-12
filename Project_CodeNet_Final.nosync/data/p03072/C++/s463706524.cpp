
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <tuple>
#include <iomanip>


using namespace std;

typedef long long ll;

const ll INF = 1ll << 60;
const ll MOD = 1e9 + 7;

bool greaterSecond(const pair<int, int>& f, const pair<int, int>& s){
	return f.second > s.second;
}

int gcd(int a, int b){
	if (b == 0)return a;
	return gcd(b, a % b);
}


int main(void){
	int n;
	cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; i++){
		cin >> h[i];
	}

	int ans = 0;
	for (int i = 0; i < n; i++){
		int highest = 0;
		for (int j = 0; j < i; j++){
			highest = max(highest, h[j]);
		}
		if (h[i] >= highest){
			ans++;
		}
	}

	cout << ans << endl;
}
