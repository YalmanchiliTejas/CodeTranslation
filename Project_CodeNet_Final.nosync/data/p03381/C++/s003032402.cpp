#include <bits/stdc++.h>

#define foreach(i,v) for(auto&& i: v)
#define all(x) (x).begin(), (x).end()

typedef std::vector< std::string > VS;
typedef std::vector<int> VI;
typedef long long ll;

template <class C> C& mini(C& a, C b) { if (b < a) a = b; return a; }
template <class C> C& maxi(C& a, C b) { if (a < b) a = b; return a; }

using namespace std;

int main(int argc, const char* argv[]) {
	int N;
	scanf("%d", &N);
	VI a(N);
	foreach (x, a)
		scanf("%d", &x);
	VI o(a);
	sort(all(a));
	int m2 = a[a.size() / 2];
	int m1 = a[a.size() / 2 - 1];
	foreach (x, o) {
		if (x <= m1)
			printf("%d\n", m2);
		else
			printf("%d\n", m1);
	}

	return 0;
}
