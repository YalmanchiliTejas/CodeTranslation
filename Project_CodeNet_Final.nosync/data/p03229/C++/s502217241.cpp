#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
constexpr int di[] = { 0, 1, 0, -1 }, dj[] = { 1, 0, -1, 0 };
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define SORT(v) sort((v).begin(), (v).end())
#define SORTR(v) sort((v).rbegin(), (v).rend())
#define all(v) (v).begin(), (v).end()
#define MAX 10000
#define nil -1
#define vmax 10000
#define sentinel 2000000000
constexpr long long int inf = 1000000000000;
constexpr long long int rinf = -(INT64_MAX);
/*cout<<fixed<<setprecision(20);cin.tie(0);ios::sync_with_stdio(false);*/

int main() {
    int n;
    cin>>n;
    ll ans1=0,ans2=0;
    deque<int> a(n,0);
    deque<int> d(n,0);
    rep(i,n) cin>>a[i];
    SORT(a);
    rep(i,n) d[i]=a[i];
    deque<int> b,c;
    b.push_back(a.front());
    a.pop_front();
    while(!a.empty()){
        b.push_front(a.back());
        a.pop_back();
        if(!a.empty()){
            b.push_back(a.back());
            a.pop_back();
        }
        if(!a.empty()){
            b.push_front(a.front());
            a.pop_front();
        }
        if(!a.empty()){
            b.push_back(a.front());
            a.pop_front();
        }
    }
    c.push_back(d.back());
    d.pop_back();
    while(!d.empty()){
        c.push_front(d.front());
        d.pop_front();
        if(!d.empty()){
            c.push_back(d.front());
            d.pop_front();
        }
        if(!d.empty()){
            c.push_front(d.back());
            d.pop_back();
        }
        if(!d.empty()){
            c.push_back(d.back());
            d.pop_back();
        }
    }
    for(int i=0;i<n-1;i++){
        ans1+=abs(b[i]-b[i+1]);
        ans2+=abs(c[i]-c[i+1]);
    }
    ans1=max(ans1,ans2);
    cout<<ans1<<endl;
}
