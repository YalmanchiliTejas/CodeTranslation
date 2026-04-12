#include <bits/stdc++.h>
using namespace std;

template<class c> auto try_out(c a) -> decltype(cerr << a, 0);
char try_out(...);

struct debug {
#ifdef LOCAL
template<class c, class d> debug& operator << (pair<c, d> e) {
	return *this << "(" << e.first << ", " << e.second << ")";
}
template<class c> typename enable_if<sizeof(try_out(declval<c>())) != 1, debug&>::type operator << (c a) {
	cerr << boolalpha << a;
	return *this;
}
template<class c> typename enable_if<sizeof(try_out(declval<c>())) == 1, debug&>::type operator << (c a) {
	*this << "[";
	for (auto it = a.begin(); it != a.end(); ++it)
		*this << ","[1 - (it != a.begin())] << *it;
	return *this << "]";
}
#else
template<class c> debug& operator << (c) {
	return *this;
}
#endif
};

#define aty(x) " [" << #x ": " << x << "] "

using ll = long long;






int main() {
	
    int n;
    cin >> n;
    if (n == 3 || n == 5 || n == 7) cout << "YES\n";
    else cout << "NO\n";
	
	
}
