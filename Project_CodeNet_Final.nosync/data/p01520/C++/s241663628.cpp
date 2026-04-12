#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <queue>
#include <bitset>

#define rep(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, n) for(int i = (a); i < (n); i++)
#define MP make_pair
#define all(s) (s).begin(), (s).end()
#define rev(s) (s).rbegin(), (s).rend()
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> P;

void test(){freopen("test.txt", "r", stdin);}

int main(){
	int N, T, E;
	cin >> N >> T >> E;
	rep(i, N){
		int x;
		cin >> x;
		if((T+E)%x <= E){
			cout << i+1 << endl;
			return 0;
		}
	}
	cout << -1 << endl;

	return 0;
}