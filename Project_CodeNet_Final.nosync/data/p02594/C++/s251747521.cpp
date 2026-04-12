#include <bits/stdc++.h>

#ifdef DEBUG
#define PRINT(x)\
    cout<<"func "<<__func__<<": line "<<__LINE__<<": "<<#x<<" = "<<(x)<<endl;
#define PRINTA(a,first,last)\
    cout<<"func "<<__func__<<": line "<<__LINE__<<": "<<#a<<"["<<(first)<<", "<<(last)<<")"<<endl;\
    for (int _i=(first);_i<(last);++_i){cout<<#a<<"["<<_i<<"] = "<<(a)[_i]<<endl;}
#define PRINTI(a,i)\
    cout<<"func "<<__func__<<": line "<<__LINE__<<": "<<#a<<"["<<#i<<"] = "<<#a<<"["<<(i)<<"] = "<<(a)[i]<<endl;
#else
#define PRINT(x)
#define PRINTA(a,first,last)
#define PRINTI(a,i)
#endif

#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);--i)
#define REP(i,n) for (int i=0;i<(n);++i)
#define RREP(i,n) for (int i=(n)-1;i>=0;--i)
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define MOD 1000000007
//#define MOD 998244353

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

template <class T, class U> void amax(T& x, U y) {if (x < y) x = y;}
template <class T, class U> void amin(T& x, U y) {if (x > y) x = y;}

template <class T, class U>
std::ostream& operator<<(std::ostream &os, const std::pair<T, U> &p) {
	os << "(" << p.first << ", " << p.second << ")";
	return os;
}
 
template <class T>
std::ostream& operator<<(std::ostream &os, const std::vector<T> &v) {
    os << "[";
	for (int i = 0; i < v.size(); ++i) {
        if (i) {
            if (i % 5 == 0) {
                os << ",\n ";
            } else {
                os << ", ";
            }
        }
		os << v[i];
	}
	os << "]";
	return os;
}

template <class T>
using vec2 = vector<vector<T>>;

template <class T>
using vec3 = vector<vector<vector<T>>>;

const int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int X;
    cin >> X;
    cout << (X >= 30 ? "Yes" : "No") << endl;
    return 0;
}
