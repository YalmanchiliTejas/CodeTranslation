#include<algorithm>
#include<bitset>
#include<climits>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<time.h>
#include<tuple>
#include<utility>
#include<vector>

using namespace std;

int main() {

	long N; cin >> N;
	vector<long> A(N); for (int i = 0; i < N; i++) cin >> A[i];

	multiset<long> colormax;//各色の最大値
    colormax.insert(A[0]);
    
	for (int i = 1; i < N; i++) {
		if (A[i] <= * colormax.begin()) { colormax.insert(A[i]); continue; }

		auto IterA = colormax.lower_bound(A[i]);
        IterA--;
		colormax.erase(IterA);
		colormax.insert(A[i]);
	}
    
	cout << colormax.size() << endl;
}