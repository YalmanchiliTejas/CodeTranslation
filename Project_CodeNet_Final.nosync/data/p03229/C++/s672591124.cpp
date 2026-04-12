#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for(ll i=0; i<n; i++)
#define repr(i, s, e) for(ll i=s; i>=e; i--)
#define reps(i, s, e) for(ll i=s; i<=e; i++)
#define inf 1e18
#define all(v) v.begin(),v.end()
#define vsort(v) sort(v.begin(), v.end())
#define vsortr(v) sort(v.begin(), v.end(), greater<ll>())
#define ceil(a, b) (a+b-1)/b
#define ok cout << "ok" << endl;
#define sp << " " <<
template<typename T> inline bool chmax(T &a, T b){ if(a<b){ a=b; return true; } return false; }
template<typename T> inline bool chmin(T &a, T b){ if(b<a){ a=b; return true; } return false; }
template<typename T> void vdebug(vector<T> v){ cout << "vdebug" << endl; for(auto vv : v){ cout << vv << " "; } cout << endl; }
template<typename T> void adebug(T arr[], ll n){ cout << "adebug" << endl; reps(i, 0, n){ cout << arr[i] << " "; } cout << endl; }
template<typename T1, typename T2> void mdebug(map<T1, T2> mp){ cout << "mdebug" << endl; for(auto const& m : mp){ cout << m.first sp m.second << endl; }}
template<typename T1, typename T2> void mldebug(multimap<T1, T2> mp){ cout << "mldebug" << endl; for(auto const& m : mp){ cout << m.first sp m.second << endl; }}
template<typename T1, typename T2> void mdebugr(map<T1, T2, greater<T1>> mp){ cout << "mdebug" << endl; for(auto const& m : mp){ cout << m.first sp m.second << endl; }}
template<typename T1, typename T2> void mldebugr(multimap<T1, T2, greater<T1>> mp){ cout << "mldebug" << endl; for(auto const& m : mp){ cout << m.first sp m.second << endl; }}
void ans(bool b){ if(b) cout << "Yes" << endl; else cout << "No" << endl; }
void ans2(bool b){ if(b) cout << "YES" << endl; else cout << "NO" << endl; }
int dx[] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, -1, 1};


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll tmpa;
    vector<ll> a, res, res2;
    cin >> n;
    rep(i, n){
        cin >> tmpa;
        a.push_back(tmpa);
    }
    
    vsort(a);
    res.push_back(a[0]);
    res2.push_back(a[n-1]);

    int l=1, r=n-1, cnt=0;;
    while(l <= r){
        if(cnt%2 == 0){
            res.push_back(a[r--]);
            if(l > r) break;
            res.insert(res.begin(), a[r--]);
        }else{
            res.push_back(a[l++]);
            if(l > r) break;
            res.insert(res.begin(), a[l++]);
        }
        cnt++;
    }

    l=0, r=n-2, cnt=0;
    while(l <= r){
        if(cnt%2 == 1){
            res2.push_back(a[r--]);
            if(l > r) break;
            res2.insert(res2.begin(), a[r--]);
        }else{
            res2.push_back(a[l++]);
            if(l > r) break;
            res2.insert(res2.begin(), a[l++]);
        }
        cnt++;
    }

    //vdebug(res);

    ll answer = 0, answer2 = 0;
    rep(i, res.size()-1){
        answer += abs(res[i+1] - res[i]);
        answer2 += abs(res2[i+1] - res2[i]);
    }

    cout << max(answer, answer2) << endl;

    return 0;
}
