#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <list>
#include <set>
#include <random>
#include <deque>
#include <unordered_set>

using namespace std;
using ll = long long;
const int BIG = 1000000007;


int main() {
    ll n,x,m;
    cin >> n >> x >> m;

    vector<ll> mark(m,-1);
    vector<ll> history;

    mark[x] = 0;
    history.push_back(x);

    ll prev = x;

    for(ll i = 1;i < n;++i){
        ll now = (prev * prev) % m;

        if(mark[now] >= 0){
            ll s = 0;
            ll siz = i - mark[now];
            
            for(ll j = mark[now];j < i;++j){
                s += history[j];
              //  cout << history[j] << endl;
            }

            ll first = 0;

            for(ll j = 0;j < mark[now];++j){
                first += history[j];
            }

            ll last = 0;

            ll lstart = mark[now] + ((n - mark[now]) / siz) * siz;

            for(ll j = lstart;j < n;++j){
                last += history[mark[now] + j - lstart];
            }

/*
            cout << "now = " << now << endl;
            cout << "mark[now] = " << mark[now] << endl;
            cout << "s = " << s << endl;
            cout << "siz = " << siz << endl;
            cout << "first = " << first << endl;
            cout << "last = " << last << endl;
            cout << "lstart = " << lstart << endl;
            */

            cout << (first + last + s * ((n - mark[now]) / siz)) << endl;
            return 0;
        }

        mark[now] = history.size();
        history.push_back(now);
        prev = now;
    }

    ll ans = 0;

    for(ll i = 0;i < n;++i){
        ans += history[i];
    }

    cout << ans << endl;
}



