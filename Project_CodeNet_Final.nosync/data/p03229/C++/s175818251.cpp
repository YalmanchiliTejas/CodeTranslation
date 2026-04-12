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


using namespace std;

int main(){

	long N;

	cin >> N;

	long long A[N];

	for(long i =0; i < N;i++){
		cin >> A[i];
	}

	sort(A, A+N);

	long long ans1 = 0, ans2 = 0;

	long long tmp1, tmp2;

	tmp2 = A[0];
	tmp1 = A[0];
	ans1 += abs(tmp1-tmp2);
	for(long i = 1; i < N; i++){
		long long x; 
		if(i % 4 == 3 || i % 4 == 0){
			x = A[i/2];
			ans1 += abs(tmp2 - x);
		} else {
			x = A[N-1 - i/2];
			ans1 += abs(x - tmp2);
		}
		tmp2 = tmp1;
		tmp1 = x;
	}

	tmp2 = A[N-1];
	tmp1 = A[N-1];
	ans2 += abs(tmp1-tmp2);
	for(long i = 1; i < N; i++){
		long long x;
		if(i % 4 == 1 || i % 4 == 2){
			x = A[i/2];
			ans2 += abs(tmp2 - x);
		} else {
			x = A[N-1 - (i/2)];
			ans2 += abs(x - tmp2);
		}
		tmp2 = tmp1;
		tmp1 = x;
	}

	ans1 = max(ans1, ans2);

	cout << ans1 << endl;

	return 0;
}
