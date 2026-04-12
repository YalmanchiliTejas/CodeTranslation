#include <iostream>
#include <cstring>
#include <cmath>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <tuple>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll,ll>;
using tll = tuple<ll,ll,ll>;
#define pb push_back
#define for1(i,n) for (ll i=0;i<(n);(i)++)
#define for2(i,m,n) for (ll i=(m);(i)<(n);(i)++)
#define for3(i,m,n,d) for (ll i=(m);(i)<(n);(i)+=(d))
#define INF (1LL << 60)
#define DEBUG 0
#if DEBUG
    #define dump(v1) dump_1(#v1, v1)
    #define dump2(v1,v2) dump_2(#v1, v1, #v2, v2)
    #define dump3(v1,v2,v3) dump_3(#v1, v1, #v2, v2, #v3, v3)
#else
    #define dump(v1)
    #define dump2(v1,v2)
    #define dump3(v1,v2,v3)
#endif
#if DEBUG
template <typename T>
void dump_1(const string& n1, const T& v1)
{
    cerr << n1 << ": " << v1 << endl;
}
template <typename T1, typename T2>
void dump_2(const string& n1, const T1& v1, const string& n2, const T2& v2)
{
    cerr << n1 << ": " << v1 << "  " << n2 << ": " << v2 << endl;
}
template <typename T1, typename T2, typename T3>
void dump_3(const string& n1, const T1& v1, const string& n2, const T2& v2, const string& n3, const T3& v3)
{
    cerr << n1 << ": " << v1 << "  " << n2 << ": " << v2 << "  " << n3 << ": " << v3 << endl;
}
template <typename T1,typename T2>
ostream& operator << (ostream& os, const pair<T1,T2>& v)
{
    os << "(" << v.first << ", " << v.second << ")";
    return os;
}
template <typename T1,typename T2, typename T3>
ostream& operator << (ostream& os, const tuple<T1,T2,T3>& v)
{
    os << "(" << get<0>(v) << ", " << get<1>(v) << ", " << get<2>(v) << ")";
    return os;
}
template <typename T>
ostream& operator << (ostream& os, const vector<T>& v)
{
    os << "[";
    for (auto it = v.begin(); it != v.end(); it++) {
        if (it != v.begin()) {
            os << ", ";
        }
        os << *it;
    }
    os << "]";
    return os;
}
template <typename T>
ostream& operator << (ostream& os, const set<T>& v)
{
    os << "{";
    for (auto it = v.begin(); it != v.end(); it++) {
        if (it != v.begin()) {
            os << ", ";
        }
        os << *it;
    }
    os << "}";
    return os;
}
template <typename T1, typename T2>
ostream& operator << (ostream& os, const map<T1,T2>& v)
{
    os << "{";
    for (auto it = v.begin(); it != v.end(); it++) {
        if (it != v.begin()) {
            os << ", ";
        }
        os << it->first << ":" << it->second;
    }
    os << "}";
    return os;
}
#endif // DEBUG
template <typename T>
void print(const T& v)
{
    cout << v << endl;
}
//---------------------------------------------------------
void solve()
{
    ll ans = 0;
    ll N;
    cin >> N;
    vll col;
    ll size = 0;
    for1(i,N) {
        ll a;
        cin >> a;
        if (size == 0) {
            col.push_back(a);
            size++;
        } else {
            if (col[0] >= a) {
                col.insert(col.begin(),a);
                size++;
            } else {
                dump(a);
                dump(col);
                ll l = -1;
                ll r = size-1;
                while (r - l > 1) {
                    ll m = (l + r) / 2;
                    dump2(m,col[m]);
                    if (col[m] >= a) {
                        r = m;
                    } else {
                        l = m;
                    }
                }
                dump3(l,r,size);
                if (col[r] < a) {
                    col[r] = a;
                } else {
                    col[l] = a;
                }
                /*/
                ll j;
                for (j = l + 1; j < size && col[j] < a; ++j) {
                    col[j-1] = col[j];
                }
                col[j-1] = a;
                */
                //sort(col.begin(),col.end());
            }
        }
        dump(col);
    }
    print(size);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}
