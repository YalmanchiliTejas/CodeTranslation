//
// Created on 2018/12/02.
//
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

#define REP(i,n) for(int i=0;i<(n);++i)
#define RREP(i,n) for(int i=(n)-1;i>=0;--i)
#define FOR(i,m,n) for(int i=m;i<(n);++i)
#define RFOR(i,m,n) for(int i=(n)-1;i>=(m);--i)
#define ALL(v) (v).begin(),(v).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());
#define dump(x) cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" \
                      << " " << __FILE__ << endl;
template<class T> bool INRANGE(T x,T a,T b) { return a<=x&&x<=b; }

#define PB push_back
#define INF 1000000001ll
#define MOD 1000000007ll
#define EPS 1e-9

const int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
const int dy[8] = { 0,1,1,1,0,-1,-1,-1 };

typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<vs> vvs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    

    int n;
    cin >> n;

    if (n == 7 || n == 5 || n == 3 ) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;

}