// F.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <functional>
#include <map>
#include <string>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <numeric>


using lolo=long long;
using namespace std;
using vec=vector<lolo>;
using pari=pair<lolo, lolo>;
using vvec=vector<vec>;
using vecb=vector<bool>;
#define FOR(i,n) for (lolo i=0; i<n; ++i)
#define FORIT(it,v) for (auto it=v.begin(); it!=v.end(); ++it)
#define FORANGE(it, v) for (auto it : v)
#define FORN(i,a,b) for (lolo i=a; i<b; ++i)
#define REV(i,a,b) for (lolo i=a; i>b; --i)
#define ALL(x) x.begin(), x.end()


template <class T>
void chmax(T& ans, const T& b)
{
	if (ans < b) {
		ans = b;
	}
}

int main()
{
	lolo N;
	cin >> N;
	vec S(N);
	FOR(i, N) cin >> S[i];
	// N-1の約数の個数?

	lolo ans = 0;

	FORN(C,1, N) {
		set<lolo> usedIndexSet;
		lolo nowScore = 0;
		lolo score = 0;
		lolo nowA = N - 1;
		const auto k_MAX = N ;
		FORN(k, 1, k_MAX+1) { 
			auto A2 = nowA - C;
			auto B = A2 - C;
			
			if (B > 0); else break;
			if (A2 != k * C); else continue;			

			if (!((usedIndexSet.count(k * C) == 0) and (usedIndexSet.count(A2 ) == 0))) {
				break;
			}

			usedIndexSet.insert(k * C);//kCとA2が追加される。
			usedIndexSet.insert(A2);
			score += S[k * C];
			score += S[A2];
			chmax(ans, score);

			nowA =A2;

		}
	}
	cout << ans << endl;
	
}