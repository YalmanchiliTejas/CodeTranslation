#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

int main(){
    int N;
    ll x[200000];
    ll y[200000];
    P p[200000];
    priority_queue<P, vector<P>, greater<P>> que;
    ll x_min = 10e+10, y_min = 10e+10;
    ll x_max = 0, y_max = 0;
    cin >> N;
    ll que_max = 0;
    for(int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
        if(x[i] > y[i]) swap(x[i], y[i]);
        p[i] = P(x[i], y[i]);
        que_max = max(que_max, y[i]);
        x_max = max(x_max, x[i]);
        x_min = min(x_min, x[i]);
        y_max = max(y_max, y[i]);
        y_min = min(y_min, y[i]);
    }
    ll ans = (x_max-x_min)*(y_max-y_min);
    sort(p, p+N);
    ll r_min = 10e+10;
    ll r_max = p[N-1].first;
    for(int i = 1; i < N; i++){
        r_min = min(r_min, p[i-1].second);
        r_max = max(r_max, p[i-1].second);
        ll tmp = (r_max-min(r_min, p[i].first))*(y_max-x_min);
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}