#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
int main(){
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    vector<ll> v(n);
    rep(i,n) cin >> v[i];
    deque<ll> deq;
    ll ans = 1;
    deq.push_back(v[0]);
    for(int i = 1; i < n; i++){
        int id = lower_bound(deq.begin(), deq.end(), v[i]) - deq.begin();
        if(id == 0){
            //cout << "Yes" << endl;
            deq.push_front(v[i]);
        }
        else deq[id-1] = v[i];
        //cout << id << endl;
    }
    cout << (int)deq.size() << endl;
    return 0;
}