#include"bits/stdc++.h"	// include
using namespace std;	// 名前空間
/* typedef */
typedef long long ll;	// long long
typedef long double ld;	// long double
typedef vector<int> vint; // intのvector
typedef vector<double> vdouble; // doubleのvector
typedef vector<ll> vll; // llのvector
typedef vector<ld> vld; // ldのvector
typedef vector<pair<ll, ll>> vl_l; // l_lのvector
typedef vector<pair<int, int>> vi_i; // i_iのvector
typedef vector<pair<double, double>> vd_d; // d_dのvector
typedef vector<string> vstring;	// stringのvector
typedef pair<ll, ll> l_l;	// ll同士のpair
typedef pair<int, int> i_i;	// int同士のpair
typedef pair<double, double> d_d;	// double同士のpair
/* define */
#define pb push_back	// push_back
#define all(v) v.begin(),v.end()	// コンテナ全体
#define PI (acos(-1))  // 円周率pi
#define rpt0(i, n) for(ll i = 0; i < (n); i++)  // リピート 0からn - 1まで
#define rpt1(i, n) for(ll i = 1; i <= (n); i++)  // リピート 1からnまで
#define rptb0(i ,n) for(ll i = (n) - 1; i >= 0; --i) // バックするリピート n - 1から0まで
#define rptb1(i ,n) for(ll i = (n); i >= 1; --i) // バックするリピート nから1まで
/* 入出力 read, write */
template <typename T>	// 1変数
void read(T& x) {
    cin >> x;
}
template <typename T, typename T0>	// 2変数
void read(T& x, T0& y) {
    cin >> x >> y;
}
template <typename T, typename T0, typename T1>	// 3変数
void read(T& x, T0& y, T1& z) {
    cin >> x >> y >> z;
}
template <typename T, typename T0, typename T1, typename T2>	// 4変数
void read(T& x, T0& y, T1& z, T2& w) {
    cin >> x >> y >> z >> w;
}
template <typename T>	// vector
void read(vector< T >& oneD, int n) {
    ll n1 = (ll)n;
    rpt0(i, n1)
    {
        ll x;
        read(x);
        oneD.push_back(x);
    }
}
template <typename T>
void read(vector< T >& oneD, ll n) {
    rpt0(i, n)
    {
        ll x;
        read(x);
        oneD.push_back(x);
    }
}
template <typename T>	// 配列
void read(T oneD[], int n) {
    ll n1 = (ll)n;
    rpt0(i, n1) {
        read(oneD[i]);
    }
}
template <typename T>
void read(T oneD[], ll n) {
    rpt0(i, n) {
        read(oneD[i]);
    }
}
template <typename T, typename T0>	// pair
void read(pair< T, T0 >& p) {
    cin >> p.first >> p.second;
}
template <typename T>	// 1変数
void write(T& x) {
    cout << x << endl;
}
template <typename T, typename T0>	// 2変数
void write(T& x, T0& y) {
    cout << x << " " << y << endl;
}
template <typename T, typename T0, typename T1>	// 3変数
void write(T& x, T0& y, T1& z) {
    cout << x << " " << y << " " << z << endl;
}
template <typename T, typename T0, typename T1, typename T2>	// 4変数
void write(T& x, T0& y, T1& z, T2& w) {
    cout << x << " " << y << " " << z << " " << w << endl;
}
template <typename T>	// vector
void write(vector< T >& oneD, int n) {
    ll n1 = (ll)n;
    rpt0(i, n1) {
        cout << oneD[i] << " ";
    }
    cout << endl;
}
template <typename T>
void write(vector< T >& oneD, ll n) {
    rpt0(i, n) {
        cout << oneD[i] << " ";
    }
    cout << endl;
}
template <typename T>	// 配列
void write(T oneD[], int n) {
    ll n1 = (ll)n;
    rpt0(i, n1) {
        write(oneD[i]);
    }
    cout << endl;
}
template <typename T>
void write(T oneD[], ll n) {
    rpt0(i, n) {
        write(oneD[i]);
    }
    cout << endl;
}
template <typename T, typename T0>	// pair
void write(pair< T, T0 >& p) {
    cout << p.first << " " << p.second << " ";
    cout << endl;
}


int main(int argc, char const *argv[])
{
    int n, m; read(n, m);
    if (n == m) cout << "Yes";
    else cout << "No";

    return 0;
}
