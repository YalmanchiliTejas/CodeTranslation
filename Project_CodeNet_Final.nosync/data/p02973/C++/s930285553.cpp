#include <bits/stdc++.h>
using namespace std;

template<class Iterator>
int LIS(Iterator l, Iterator r){
	auto x = *l;
	pair<int, decltype(x)> p1x(1, x);
//	printf("p1x = (%d, %d)\n", p1x.first, p1x.second);
	vector<pair<int, decltype(x)>> dp(r - l + 1, p1x);
/*	for(int i = 0; i < dp.size(); i++){
		printf("dp[%d] = (%d, %d)\n", i, dp[i].first, dp[i].second);
	}
*/	const auto comp = [&](pair<int, decltype(x)> a, pair<int, decltype(x)> b){
		return a.first != b.first ? a.first < b.first : a.second < b.second;
	};
	for(Iterator i = l; i < r; i++){
		pair<int, decltype(x)> val(0, *i);
//		printf("val[%d] = (%d, %d)\n", i - l, val.first, val.second);
//		printf("%d\n", lower_bound(dp.begin(), dp.end(), val, comp) - dp.begin());
		*lower_bound(dp.begin(), dp.end(), val, comp) = val;
	}
/*	for(int i = 0; i < dp.size(); i++){
		printf("dp[%d] = (%d, %d)\n", i, dp[i].first, dp[i].second);
	}
*/	return lower_bound(dp.begin(), dp.end(), p1x, comp) - dp.begin();
/*	if(r - l <= 1) return 0;
	Iterator i, j, k, h = l + (r - l) / 2;
	int ans = inversion_number(l, h) + inversion_number(h, r);
	auto x = *l;
	vector<decltype(x)> tmp(l, r);
	for(i = l, j = l, k = h; i < r; i++){
		if(k == r || (j < h && tmp[j - l] <= tmp[k - l])){
			*i = tmp[j - l];
			j++;
		}
		else{
			*i = tmp[k - l];
			ans += k - i;
			k++;
		}
	}
	return ans;
*/
}
/*
int LIS(int *array, int N){
	int i, l, h, r;
	int *dp = (int *)malloc(sizeof(int) * (N + 2));
	dp[0] = -inf;
	for(i = 1; i <= N + 1; i++){
		dp[i] = inf;
	}
	for(i = 0; i < N; i++){
		l = 0;
		r = N + 1;
		while(r - l > 1){
			h = (l + r) / 2;
			if(dp[h] > array[i]){ // > なら広義, >= なら狭義の単調増加
				r = h;
			}
			else{
				l = h;
			}
		}
		dp[r] = array[i];
	}
	for(i = 0; dp[i] < inf; i++){}
	return i - 1;
}
*/

int main(){
	int N, i;
	scanf("%d", &N);
	vector<int> A(N);
	for(i = 0; i < N; i++){
		scanf("%d", &A[i]);
	}
//	printf("LISA = %d\n", LIS(A.begin(), A.end()));
	vector<pair<int, int>> B(N);
	for(i = 0; i < N; i++){
		B[i].first = -A[i];
		B[i].second = i;
	}
	printf("%d\n", LIS(B.begin(), B.end()));
	return 0;
}