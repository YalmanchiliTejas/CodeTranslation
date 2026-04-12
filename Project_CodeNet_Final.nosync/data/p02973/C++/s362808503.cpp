#include <bits/stdc++.h>
#define REP(i, n) for(int i=0; i<(int)(n); i++)
#define REP1(i,a,b) for(int i=a; i<=(int)(b); i++)
#define ALL(x) begin(x),end(x)
#define PB push_back
using namespace std;
typedef int64_t LL;
typedef vector<int> VI;
typedef pair<int,int> PII;

template<class T> inline bool chmax( T &a, const T &b ) { return b>a ? a=b,true : false; }
template<class T> inline bool chmin( T &a, const T &b ) { return b<a ? a=b,true : false; }
template<class T> using MaxHeap = priority_queue<T>;
template<class T> using MinHeap = priority_queue<T, vector<T>, greater<T>>;
template<class T, class F=less<T>> void sort_uniq( vector<T> &v, F f=F() ) {
    sort(begin(v),end(v),f);
    v.resize(unique(begin(v),end(v))-begin(v));
}

VI a,v;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    a.resize(n);
    REP(i,n) cin >> a[i];
    reverse(ALL(a));

    // lis
    REP(i,n) {
        if(v.size()==0) v.push_back(a[i]);
        else {
            if(v.back()<=a[i]) v.push_back(a[i]);
            else {
                *upper_bound(ALL(v),a[i])=a[i];
            }
        }
    }
    cout << v.size() << '\n';
    return 0;
}