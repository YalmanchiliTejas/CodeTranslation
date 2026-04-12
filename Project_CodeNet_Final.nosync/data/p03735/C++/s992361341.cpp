#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define ALL(v) (v).begin(),(v).end()
#define one first
#define two second
typedef long long ll;
typedef pair<int, int> pi;
const int INF = 0x3f2f1f0f;
const ll LINF = 1ll * INF * INF;

const int MAX_N = 2e5 + 10;

int N; pi Nr[MAX_N];
void update(pi &now, int val) {
	now.one = min(now.one, val);
	now.two = max(now.two, val);
}
ll calc(const pi &a, const pi &b) {return 1ll * (a.two - a.one) * (b.two - b.one);}
pi getRange(multiset<int> &s) {return pi(*s.begin(), *s.rbegin());}
int main() {
	cin >> N; 
	for(int i=0; i<N; i++) scanf("%d%d", &Nr[i].one, &Nr[i].two);
	for(int i=0; i<N; i++) if(Nr[i].one > Nr[i].two) swap(Nr[i].one, Nr[i].two);
	sort(Nr, Nr+N);

	ll ans = LINF;
	pi lv = pi(Nr[0].one, Nr[0].one), rv = pi(Nr[0].two, Nr[0].two);
	for(int i=0; i<N; i++) update(lv, Nr[i].one), update(rv, Nr[i].two);
	ans = min(ans, calc(lv, rv));

	pi range = pi(Nr[0].one, Nr[0].two);
	for(int i=0; i<N; i++) update(range, Nr[i].one), update(range, Nr[i].two);

	multiset<int> list;
	for(int i=0; i<N; i++) list.insert(Nr[i].one);
	ans = min(ans, calc(range, getRange(list)));
	for(int i=0; i<N; i++) {
		list.erase(list.find(Nr[i].one)), list.insert(Nr[i].two);
		ans = min(ans, calc(range, getRange(list)));
	}

	printf("%lld\n", ans);
	return 0;
}
