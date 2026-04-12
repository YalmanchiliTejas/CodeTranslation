#include <bits/stdc++.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <cassert>
#include <queue>
#include <random>
#include <stack>
#include <iomanip>
#include <math.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)n; i++)
#define repf(i, a, b) for (ll i = (ll)a; i < (ll)b; i++)
#define repr(i, a, b) for (ll i = (ll)a; i > (ll)b; i--)
#define repv(x, arr) for (auto &x : arr)
#define all(v) (v).begin(), (v).end()
#define vec(name, num) vector<ll> name((num), 0);
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<int> vii;
typedef vector<vii> vvii;
const ll mod = 1e9 + 7;
const int infi = 2147483600;
const ll infl = 1e17;

ll last(vll& tar){
    return tar[tar.size() - 1];
}

int main()
{
    int n;
    cin >> n;
    vll a(n);
    rep(i, n) cin >> a[i];
    sort(all(a));
    vll seiri;
    ll ans = 0;
    if (last(a)<n){
        cout << 0 << endl;
        return 0;
    }
    seiri.push_back(last(a));
    a.pop_back();
    rep(i,n-1)
    {
        /*cout << "a: ";
        for (auto x : a)
            cout << x << " ";
        cout << endl;
        cout << "seiri: ";
        for (auto x : seiri)
            cout << x << " ";
        cout << endl; */
        if (last(a)>last(seiri)-n){
            seiri.push_back(last(a));
            a.pop_back();
            sort(all(seiri));
        }
        else{
            ll x = (seiri[0] - last(a)) / (n + 1);
            //cout << x << endl;
            ans += x * seiri.size();
            rep(i,seiri.size()){
                seiri[i] += (-n + seiri.size() - 1) * x;
            }
            rep(i,a.size()){
                a[i] += x * seiri.size();
            }
            while (1){
                if (last(a)>last(seiri)-n){
                    break;
                }
                ans++;
                seiri[seiri.size() - 1] -= n;
                rep(i,seiri.size()-1){
                    seiri[i]++;
                }
                sort(all(seiri));
                rep(i,a.size()){
                    a[i]++;
                }
            }
            seiri.push_back(last(a));
            a.pop_back();
            sort(all(seiri));
        }
    }
    if (seiri[0]>n){
    ll x = seiri[0] - n + 1;
    ans += x * n;
    rep(i,n){
        seiri[i] -= x;
    }}
    while (1)
    {
        if (last(seiri)<n)
        {
            break;
        }
        ans++;
        seiri[seiri.size() - 1] -= n;
        rep(i, seiri.size() - 1)
        {
            seiri[i]++;
        }
        sort(all(seiri));
    }
    cout << ans << endl;
}