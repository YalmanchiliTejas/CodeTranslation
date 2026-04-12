#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <tuple>

#define DEBUG(x) cout<<#x<<": "<<x<<endl

using namespace std;

int main(){

	int N;

	cin >> N;

	int H[N];

	for(int i = 0; i<N; i++){
		cin >> H[i];
	}

	int m = H[0];
	int ans = 1;

	for(int i = 1; i<N; i++){
		m = max(m, H[i-1]);
		if(m <= H[i]) ans++;
	}

	cout << ans << endl;

	return 0;
}
