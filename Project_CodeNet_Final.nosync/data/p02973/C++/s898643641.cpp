#include <bits/stdc++.h>
using namespace std;

template<class Iterator>
int LIS(Iterator l, Iterator r){
	auto x = *l;
	pair<int, decltype(x)> p1x(1, x);
	vector<pair<int, decltype(x)>> dp(r - l, p1x);
	for(Iterator i = l; i < r; i++){
		pair<int, decltype(x)> val(0, *i);
		//lower_boundなら狭義, upper_boundなら広義の単調増加
		*lower_bound(dp.begin(), dp.end(), val) = val;
	}
	return lower_bound(dp.begin(), dp.end(), p1x) - dp.begin();
}

template<class Iterator, class Compare>
int LIS(Iterator l, Iterator r, Compare comp){
	auto x = *l;
	pair<int, decltype(x)> p1x(1, x);
	vector<pair<int, decltype(x)>> dp(r - l, p1x);
	const auto compair = [&](pair<int, decltype(x)> a, pair<int, decltype(x)> b){
		return a.first != b.first ? a.first < b.first : comp(a.second, b.second);
	};
	for(Iterator i = l; i < r; i++){
		pair<int, decltype(x)> val(0, *i);
		//lower_boundなら狭義, upper_boundなら広義の単調増加
		*lower_bound(dp.begin(), dp.end(), val, compair) = val;
	}
	return lower_bound(dp.begin(), dp.end(), p1x, compair) - dp.begin();
}

int main(){
	int N, i;
	scanf("%d", &N);
	vector<int> A(N);
	for(i = 0; i < N; i++){
		scanf("%d", &A[i]);
//		A[i] = -A[i];
	}
/*	printf("%d\n", LIS(A.begin(), A.end()));
	return 0;
*/	vector<pair<int, int>> B(N);
	for(i = 0; i < N; i++){
		B[i].first = i;
		B[i].second = A[i];
	}
	printf("%d\n", LIS(B.begin(), B.end(), [](pair<int, int> a, pair<int, int> b){
		if(a.second != b.second){
			return a.second > b.second;
		}
		else{
			return a.first < b.first;
		}
	}));
	return 0;
}