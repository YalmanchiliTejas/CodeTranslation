#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <numeric>
#include <map>
#include <vector>
#include <string>
#include <vector>
#include <cassert>
#include <cmath>
#include <stack>
#include <cctype>
#include <queue>
#include <algorithm>
#include <memory>
#include <memory.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> PP;
const int INF = 1 << 30;
const double EPS = 1e-10;
const double PI = 3.14159;

int A[200];

int main(){
	int n;
	while(cin >> n && n){
		for(int i = 0; i < n; i++){
			cin >> A[i];
		}
		int m = *max_element(A, A + n);
		int mi = *min_element(A, A + n);
		int res = accumulate(A, A + n, 0);
		cout << (res - m - mi) / (n - 2) << endl;
	}
	return 0;
}