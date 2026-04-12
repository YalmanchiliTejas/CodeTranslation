#include <bits/stdc++.h>

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 999999999
#define MOD 1000000007

using namespace std;
typedef pair<int, int> P;
typedef pair<llong, llong> LP;
typedef pair<int, P> PP;
typedef pair<llong, LP> LPP;

int iy[]={0, 0, 1, -1};
int ix[]={1, -1, 0, 0};

int n, m, l;

int main(){
	cin >> n >> m >> l;
	cout << (n-l)/(m+l) << endl;
	return 0;
}