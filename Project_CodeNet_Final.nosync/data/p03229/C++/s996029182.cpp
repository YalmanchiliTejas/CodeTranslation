#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define FOR(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
#define MOD (1000000007)
#define INF (2e9)
#define INFL (2e18)

typedef long long ll;
typedef unsigned int ui;
typedef unsigned long long ull;
using vint=vector<int>;
using vll=vector<ll>;
template<class T>using arr=vector<vector<T>>;
template<class T>int popcount(T &a){int c=0; rep(i, 8*(int)sizeof(a)){if((a>>i)&1) c++;} return c;}
template<class T>void pr(T x){cout << x << endl;}
template<class T>void prvec(vector<T>& a){rep(i, a.size()-1){cout << a[i] << " ";} pr(a[a.size()-1]);}
template<class T>void prarr(arr<T>& a){rep(i, a.size()) if(a[i].empty()) pr(""); else prvec(a[i]);}
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main()
{
    int n; cin >> n;
    vint a(n);
    deque<int> b;
    rep(i, n) cin >> a[i];
    sort(ALL(a));

    vint ap = a;
    ll t=0;
    b.push_back(a[0]);
    int l=1, r=n-1, c=0;
    while(l<=r){
        if(c%2==0){
            // pr('a');
            int k = b.back();
            t += abs(k - a[r]);
            b.push_back(a[r--]);
            if(l>r) break;
            k = b.front();
            t += abs(k - a[r]);
            b.push_front(a[r--]);
        }else{
           int k = b.back();
            t += abs(k - a[l]);
            b.push_back(a[l++]);
            if(l>r) break;
            k = b.front();
            t += abs(k - a[l]);
            b.push_front(a[l++]);
        }
        c++;
    }
    // while(!b.empty()){
    //     pr(b.front());
    //     b.pop_front();
    // }
    // // pr("");
    ll ans = t;
    reverse(ALL(a));
    t=0;
    b.clear();
    b.push_back(a[0]);
    l=1; r=n-1; c=0;
    while(l<=r){
        if(c%2==0){
            // pr('a');
            int k = b.back();
            t += abs(k - a[r]);
            b.push_back(a[r--]);
            if(l>r) break;
            k = b.front();
            t += abs(k - a[r]);
            b.push_front(a[r--]);
        }else{
           int k = b.back();
            t += abs(k - a[l]);
            b.push_back(a[l++]);
            if(l>r) break;
            k = b.front();
            t += abs(k - a[l]);
            b.push_front(a[l++]);
        }
        c++;
    }
    // while(!b.empty()){
    //     pr(b.front());
    //     b.pop_front();
    // }
    // pr(t);
    pr(max(ans, t));
    return 0;}