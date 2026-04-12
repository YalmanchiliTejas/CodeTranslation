#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include <unordered_map>
//#include"testlib.h"
#define endl "\n"
#define all(v) v.begin(),v.end()
#define allr(s) s.rbegin(),s.rend()
#define RT(s) return cout<<s,0
#define watch(x) cout << (#x)<<" = "<<x<<endl
#define sz(s)    (int)(s.size())
#define PI acos(-1)
#define EPS 1e-8
using namespace std;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> row;
typedef vector<row> matrix;
typedef pair<double, double> point;
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };

void fast() {
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
}

int main() {
	fast();
	string str; cin >> str;
	sort(all(str));
	if (str[0] != str.back())
		cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}