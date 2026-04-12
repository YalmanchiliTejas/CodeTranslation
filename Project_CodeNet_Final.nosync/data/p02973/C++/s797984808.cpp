#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define REP(i, n) FOR(i, 0, (n))
#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define LAR(a, b) ((a)=max((a),(b)))
#define SML(a, b) ((a)=min((a),(b)))
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<int, int>> vpii;
typedef pair<int, int> pii;
#define PB push_back
#define EB emplace_back
#ifdef LOCAL_DEBUG
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

class BIT
{
public:
    vector<int> bit;
    int M;

    BIT(int M):
        bit(vector<int>(M+1, 0)), M(M) {}

    int sum_(int i) {
        if (!i) return 0;
        return bit[i] + sum_(i-(i&-i));
    }

		int sum(int i){
			return sum_(i+1);
		}

    void add_(int i, int x) {
        if (i > M) return;
        bit[i] += x;
        add_(i+(i&-i), x);
    }
		
		void add(int i, int x){
			add_(i+1, x);
		}
};

#define N 112345
int a[N];
multiset<int> s;

int main(){
	int n; scanf("%d", &n);
	REP(i, n){
		scanf("%d", a+i);
	}
	int ans = 0;
	for(int i = n-1; i>=0; i--){
		auto it = s.upper_bound(a[i]);
		if(it == s.end()){
			ans++;
		} else {
			s.erase(it);
		}
		s.insert(a[i]);
	}
	printf("%d\n", ans);
}



