#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

typedef long long ll;
typedef pair<int, int> P;

#define For(i, a, b) for(int i = (a); i < (b); i++)
#define Rep(i, n) For(i, 0, (n))
#define Rrep(i, n) for(int i = (n - 1); i >= 0; i--)
#define pb push_back

const int inf = 999999999;
const int mod = 1000000007;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int main(){
	int n; cin >> n; int a[n], b[n];
	Rep(i, n){
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + n);
	int k = b[(n/2) - 1], l = b[(n/2)];
	Rep(i, n){
		if(a[i] <= k){
			cout << l << endl;
		}else if(a[i] >= l){
			cout << k << endl;
		}
	}
}