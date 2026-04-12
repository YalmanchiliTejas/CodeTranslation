#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e5 + 5;

int A[MAXN], N, bit[MAXN], cnt[MAXN];
pair<int, int> B[MAXN];
map<int, int> mp;

void update(int pos, int v){
	for(; pos<=N; pos+=(pos&(-pos))) bit[pos] += v;
}

int query(int pos){
	int res = 0;
	for(; pos>0; pos-=(pos&(-pos))) res += bit[pos];
	return res;
}

int main(){
	scanf("%d", &N);
	for(int i=1; i<=N; ++i){ scanf("%d", &B[i].first); B[i].second = i; }
	sort(B + 1, B + N + 1);
	int c = 0;
	for(int i=1; i<=N; ++i){
		if(B[i].first != B[i - 1].first) c++;
		A[B[i].second] = c;
		mp[c] = B[i].first;
		cnt[c]++;
	}
	for(int i=1; i<=N; ++i) update(A[i], +1);
	int sz = (N / 2) - 1;
	for(int i=1; i<=N; ++i){
		update(A[i], -1);
		cnt[A[i]]--;
		int lo = 1, hi = N, mid, res = -1;
		while(lo <= hi){
			mid = (lo + hi)>>1;
			int x = query(mid - 1);
			if(x <= sz && x + cnt[mid] > sz) res = mid, hi = mid - 1;
			else if(x > sz) hi = mid - 1;
			else lo = mid + 1;
		}
		printf("%d\n", mp[res]);
		cnt[A[i]]++;
		update(A[i], +1);
	}
	return 0;
}