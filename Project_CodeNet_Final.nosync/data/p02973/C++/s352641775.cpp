#include <bits/stdc++.h>
using namespace std;

template<class Iterator>
int LIS(Iterator l, Iterator r){
	auto x = *l;
	pair<int, decltype(x)> p1x(1, x);
	vector<pair<int, decltype(x)>> dp(r - l, p1x);
	const auto comp = [&](pair<int, decltype(x)> a, pair<int, decltype(x)> b){
		return a.first != b.first ? a.first < b.first : a.second < b.second;
	};
	for(Iterator i = l; i < r; i++){
		pair<int, decltype(x)> val(0, *i);
		*upper_bound(dp.begin(), dp.end(), val, comp) = val;
	}
	return lower_bound(dp.begin(), dp.end(), p1x, comp) - dp.begin();
}

int main(){
	int N, i;
	scanf("%d", &N);
	vector<int> A(N);
	for(i = 0; i < N; i++){
		scanf("%d", &A[i]);
		A[i] = -A[i];
	}
	printf("%d\n", LIS(A.begin(), A.end()));
	return 0;
	vector<pair<int, int>> B(N);
	for(i = 0; i < N; i++){
		B[i].first = -A[i];
		B[i].second = i;
	}
	printf("%d\n", LIS(B.begin(), B.end()));
	return 0;
}