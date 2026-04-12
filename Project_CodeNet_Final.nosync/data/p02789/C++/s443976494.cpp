#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define all(v) v.begin(), v.end()
#define F first
#define S second
#define FOR(i, n) for(int i = 0; i < (int) n; i++)

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

int main(){
	ios::sync_with_stdio(false); cin.tie(0);

	int n, m; cin >> n >> m;
	if(m == n) cout << "Yes\n";
	else cout << "No\n";

	return 0;
}