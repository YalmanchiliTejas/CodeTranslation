#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>

#define For(i, j, k) for(int i = j; i <= k; i++)
#define Forr(i, j, k) for(int i = j; i >= k; i--)

using namespace std;

const int N = 400010;

struct Box{
	int x, y;
}A[N];

struct Node{
	int num, id;

	bool operator < (const Node& B) const{
		return num < B.num;
	}
}B[N];

int n, m;
bool vis[N];

set<int> S;

int main(){
	scanf("%d", &n);
	int Mx = 0, Mn = 1e9;
	For(i, 1, n){
		scanf("%d%d", &A[i].x, &A[i].y);
		if(A[i].y < A[i].x) swap(A[i].x, A[i].y);
		Mx = max(Mx, A[i].y), Mn = min(Mn, A[i].x);
	}

	int xmax = Mn, ymin = Mx;
	For(i, 1, n){
		xmax = max(xmax, A[i].x);
		ymin = min(ymin, A[i].y);
	}
	long long ans1 = 1ll * (xmax - Mn) * (Mx - ymin);
	
	long long ans2 = 1e18;
	For(i, 1, n) B[++m] = (Node){A[i].x, i}, B[++m] = (Node){A[i].y, i}, S.insert(A[i].x);
	sort(B + 1, B + m + 1);
	For(i, 1, m){
		int x = B[i].id;
		ans2 = min(ans2, 1ll * (Mx - Mn) * (*S.rbegin() - B[i].num));
		S.erase(A[x].x), S.insert(A[x].y);
		if(vis[x]) break;
		vis[x] = true;
	}

	printf("%lld\n", min(ans1, ans2));
	return 0;
}