#include<iostream>
#include<string>
#include <vector>
#include<algorithm>
using namespace std;
using vi = vector<int>;
using vii = vector<vi>;
using pii = pair<int, int>;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define vsort(v) sort(v.begin(), v.end())
#define ll long long
const ll MOD = 1e9 + 7;

int main() {
	int r, g, b;
	cin >> r >> g >> b;
	if ((100 * r + 10 * g + b) % 4 == 0)cout << "YES" << endl;
	else cout << "NO" << endl;
}