#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define int ll

// [a -> b-1]
#define reps(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
// [0 -> a-1]
#define rep(i, a) reps(i, 0, (a))
// [a-1 -> b]
#define rreps(i, a, b) for (int i = (int)((a)-1); i >= (int)(b); i--)
// [a-1 -> 0]
#define rrep(i, a) rreps(i, a, 0)
#define all(v) (v).begin(), (v).end()
// next_permutation(all(v))
#define PERM(v) next_permutation(all(v))
/*sort(all(v));
 * (v).erase(unique(all(v)), v.end())*/
#define UNIQUE(v)\
	sort(all(v));\
	(v).erase(unique(all(v)), v.end())
// b is [a, c)
#define RANGE(a, b, c) ((a) <= (b) && (b) < (c))
// c is [a, e) && d is [b, f)
#define RANGE2D(a, b, c, d, e, f) (RANGE((a), (c), (e)) && RANGE((b), (d), (f)))
#define chmin(a, b) a = min(a, (b))
#define chmax(a, b) a = max(a, (b))
#define fcout cout << fixed << setprecision(15)
#define YES(f) cout << ((f) ? YES_STR : NO_STR) << endl;

#ifdef LOCAL_DEBUG_OPTION
template<class T, class U = remove_const_t<remove_reference_t<T>>>
enable_if_t<is_integral<U>::value && !is_same<U, bool>::value> DUMP_SUB_FUNCTION(T x) {
	cerr << x;
}
template<class T, class U = remove_const_t<remove_reference_t<T>>>
enable_if_t<is_same<U, bool>::value> DUMP_SUB_FUNCTION(T x) {
	if (x) cerr << "True";
	else cerr << "False";
}
template<class T, class U = remove_const_t<remove_reference_t<T>>>
enable_if_t<is_same<U, string>::value> DUMP_SUB_FUNCTION(T x) {
	cerr << '\"' << x << '\"';
}
template<class T>
enable_if_t<is_same<T, const char*>::value> DUMP_SUB_FUNCTION(T x) {
	cerr << '\"' << string(x) << '\"';
}
template<class T>
enable_if_t<true> DUMP_SUB_FUNCTION(vector<T> x) {
	cerr << '{';
	for (size_t i = 0; i < x.size(); i++) {
		if (i) cerr << ", ";
		DUMP_SUB_FUNCTION(x[i]);
	}
	cerr << '}';
}
template<class T>
enable_if_t<true> DUMP_SUB_FUNCTION(set<T> x) {
	cerr << '{';
	size_t i = 0;
	for (auto itr = x.begin(); itr != x.end(); itr++, i++) {
		if (i) cerr << ", ";
		DUMP_SUB_FUNCTION(*itr);
	}
	cerr << '}';
}
template<class T, class U>
enable_if_t<true> DUMP_SUB_FUNCTION(map<T, U> x) {
	cerr << '{';
	size_t i = 0;
	for (auto itr = x.begin(); itr != x.end(); itr++, i++) {
		if (i) cerr << ", ";
		DUMP_SUB_FUNCTION(itr->first);
		cerr << " : ";
		DUMP_SUB_FUNCTION(itr->second);
	}
	cerr << '}';
}
template<class T, class U = remove_const_t<remove_reference_t<T>>>
enable_if_t<is_floating_point<U>::value> DUMP_SUB_FUNCTION(T x) {
	cerr << fixed << setprecision(5) << x;
}
template<class T, class U>
enable_if_t<true> DUMP_SUB_FUNCTION(pair<T, U> p) {
	cerr << '(';
	DUMP_SUB_FUNCTION(p.first);
	cerr << ", ";
	DUMP_SUB_FUNCTION(p.second);
	cerr << ')';
}
#define dump_sub_function1(v) do {\
	DUMP_SUB_FUNCTION(v); \
} while (0);
#define dump_sub_function2(v1, v2) do {\
	dump_sub_function1((v1)); cerr << ' '; \
	dump_sub_function1((v2)); \
} while (0);
#define dump_sub_function3(v1, v2, v3) do {\
	dump_sub_function1((v1)); cerr << ' '; \
	dump_sub_function2((v2), (v3)); \
} while (0);
#define dump_sub_function4(v1, v2, v3, v4) do {\
	dump_sub_function1((v1)); cerr << ' '; \
	dump_sub_function3((v2), (v3), (v4)); \
} while (0);
#define dump_sub_function5(v1, v2, v3, v4, v5) do {\
	dump_sub_function1((v1)); cerr << ' '; \
	dump_sub_function4((v2), (v3), (v4), (v5)); \
} while (0);
#define dump_sub_function6(v1, v2, v3, v4, v5, v6) do {\
	dump_sub_function1((v1)); cerr << ' '; \
	dump_sub_function5((v2), (v3), (v4), (v5), (v6)); \
} while (0);
#define GET_KTH_FUNCION_NAME(v1, v2, v3, v4, v5, v6, NAME, ...) NAME
#define dump(...) do { \
	GET_KTH_FUNCION_NAME(__VA_ARGS__, dump_sub_function6, dump_sub_function5, dump_sub_function4, dump_sub_function3, dump_sub_function2, dump_sub_function1)(__VA_ARGS__); \
	cerr << endl; \
} while (0);
#else
#define dump(...) ;
#endif

const string YES_STR = "Yes";
const string NO_STR = "No";

signed main(){
	int a, b; cin >> a >> b;
	YES(a == b);
	return 0;
}

