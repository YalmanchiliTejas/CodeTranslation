#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define ALL(A) A.begin(), A.end()

using namespace std;

typedef long long ll;

ll L[51];	// L[i]: i 層までの長さ
ll P[51]; 	// P[i]: i 層までのパッティの数

void dfsL(int depth, ll length){
	L[depth] = length;
	if (depth == 50){
		return;
	} // end if

	dfsL(depth + 1, 2LL * length + 3LL);
}

void dfsP(int depth, ll num){
	P[depth] = num;
	if (depth == 50){
		return;
	} // end if

	dfsP(depth + 1, 2LL * num + 1LL);
}

int main()
{
	memset(L, 0LL, sizeof(L));
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	dfsL(0,1LL);
	dfsP(0,1LL);
	
	ll N, X; cin >> N >> X;

/*
	rep (i, N + 1){
		cerr << "i: " << setw(2) << i << " length: " << setw(16) << L[i]  << " #patti: " << setw(16) << P[i] << endl;
	} // end rep
	cerr << endl;
*/

	ll res = 0LL;
	int m = N;

	while(X > 0LL && m > 0){
		if (X == 1LL){
			break;
		}else
		if (X > 1LL && X <= L[m-1] + 1LL){
			--X;
		}else
		if (X == L[m-1] + 2LL){
			res += P[m-1] + 1LL;
			break;
		}else
		if (X > L[m-1] + 2LL && X <= 2LL * L[m-1] + 2LL){
			res += P[m-1] + 1LL;
			X -= L[m-1] + 2LL;
		}else
		if (X == 2LL * L[m-1] + 3LL){
			res += 2LL * P[m-1] + 1LL;
			break;
		} // end if
		--m;
	} // end while

	res += (int)(m == 0 && X == 1LL);

	cout << res << endl;
	
	return 0;
}