#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const int MOD = 1e9 + 7;

int main(){
	int x,y,z;
	cin >> x >> y >> z;
	x -= z;
	cout << x / (y + z) << endl;
}