#include <bits/stdc++.h>
using namespace std;

int N, mna[200005], mxa[200005], mnb[200005], mxb[200005], mna0[200005], mxa0[200005], mnb0[200005], mxb0[200005];
pair<int, int> P[200005];

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		P[i] = make_pair(min(x, y), max(x, y));
	}
	sort(P, P + N);
	int mn0 = 1000000000, mx0 = 0, mn1 = 1000000000, mx1 = 0;
	for (int i = 0; i < N; i++) {
		mn0 = min(mn0, P[i].first);
		mx0 = max(mx0, P[i].first);
		mn1 = min(mn1, P[i].second);
		mx1 = max(mx1, P[i].second);
		mna[i] = mn0;
		mnb[i] = mn1;
		mxa[i] = mx0;
		mxb[i] = mx1;
	}
	mn0 = 1000000000;
	 mx0 = 0; mn1 = 1000000000; mx1 = 0;
	 for (int i = N - 1; i >= 0; i--) {
		mn0 = min(mn0, P[i].first);
		mx0 = max(mx0, P[i].first);
		mn1 = min(mn1, P[i].second);
		mx1 = max(mx1, P[i].second);
		mna0[i] = mn0;
		mnb0[i] = mn1;
		mxa0[i] = mx0;
		mxb0[i] = mx1;
	}
	/*
	long long ans1 =  abs((long long)(mx0 - mn1) * (mx1 - mn0));
	long long ans2 = (long long)(mx0 - mn0) * (mx1 - mn1);*/
	long long ans = 2000000000000000000ll;
	
	for (int i = 0; i <= N; i++) {
		int a = max(((i == 0) ? 0 : mxa[i - 1]), ((i == N) ? 0 : mxb0[i])) - min(((i == 0) ? 1000000000 : mna[i - 1]), ((i == N) ? 1000000000 : mnb0[i]));
		int b = max(((i == 0) ? 0 : mxb[i - 1]), ((i == N) ? 0 : mxa0[i])) - min(((i == 0) ? 1000000000 : mnb[i - 1]), ((i == N) ? 1000000000 : mna0[i]));
		ans = min(ans, (long long)a * b);
	}
	for (int i = 0; i < N; i++) swap(P[i].first, P[i].second);
	sort(P, P + N);
	mn0 = 1000000000;
	 mx0 = 0; mn1 = 1000000000; mx1 = 0;
	for (int i = 0; i < N; i++) {
		mn0 = min(mn0, P[i].first);
		mx0 = max(mx0, P[i].first);
		mn1 = min(mn1, P[i].second);
		mx1 = max(mx1, P[i].second);
		mna[i] = mn0;
		mnb[i] = mn1;
		mxa[i] = mx0;
		mxb[i] = mx1;
	}
	mn0 = 1000000000;
	 mx0 = 0; mn1 = 1000000000; mx1 = 0;
	 for (int i = N - 1; i >= 0; i--) {
		mn0 = min(mn0, P[i].first);
		mx0 = max(mx0, P[i].first);
		mn1 = min(mn1, P[i].second);
		mx1 = max(mx1, P[i].second);
		mna0[i] = mn0;
		mnb0[i] = mn1;
		mxa0[i] = mx0;
		mxb0[i] = mx1;
	}
	for (int i = 0; i <= N; i++) {
		int a = max(((i == 0) ? 0 : mxa[i - 1]), ((i == N) ? 0 : mxb0[i])) - min(((i == 0) ? 1000000000 : mna[i - 1]), ((i == N) ? 1000000000 : mnb0[i]));
		int b = max(((i == 0) ? 0 : mxb[i - 1]), ((i == N) ? 0 : mxa0[i])) - min(((i == 0) ? 1000000000 : mnb[i - 1]), ((i == N) ? 1000000000 : mna0[i]));
		ans = min(ans, (long long)a * b);
	}
	printf("%lld\n", ans);
}
