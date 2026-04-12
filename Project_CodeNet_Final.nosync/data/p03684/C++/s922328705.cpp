#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
using namespace std;

struct Point{
    long long x, y;
};

struct Dis_num{
    long long dis;
    int p;
    bool operator < ( const Dis_num &right ) const {
        return dis < right.dis;
    }
};

Point xy[100005];
vector<int> xt[100005], yt[100005];

int main(){
    int n;
    cin >> n;

    rep(i,n) cin >> xy[i].x >> xy[i].y;

    Dis_num xn[100005], yn[100005];
    rep(i,n){
        xn[i] = {xy[i].x, i};
        yn[i] = {xy[i].y, i};
    }

    sort(xn, xn + n);
    sort(yn, yn + n);
    rep(i,n){
        if(i == 0){
            xt[ xn[i].p ].emplace_back(xn[i + 1].p);
            yt[ yn[i].p ].emplace_back(yn[i + 1].p);
        }else if(i == n - 1){
            xt[ xn[i].p ].emplace_back(xn[i - 1].p);
            yt[ yn[i].p ].emplace_back(yn[i - 1].p);
        }else{
            xt[ xn[i].p ].emplace_back(xn[i + 1].p);
            xt[ xn[i].p ].emplace_back(xn[i - 1].p);
            yt[ yn[i].p ].emplace_back(yn[i + 1].p);
            yt[ yn[i].p ].emplace_back(yn[i - 1].p);
        }
    }

    typedef pair<long long,long long> pl;
    priority_queue<long long, vector<pl>, greater<pl>> q;
    //priority_queue<pair<long long, int>> q;
    q.push(make_pair(0,0));

    vector<bool> used(n,0);
    long long ans = 0;
    while(not q.empty()){
        pair<long long, int> u = q.top(); q.pop();
        if(used[u.second]) continue;
        used[u.second] = true;
        ans += u.first;

        for(auto i : xt[u.second]){
            q.push(make_pair(abs(xy[u.second].x - xy[i].x), i));
        }
        for(auto i : yt[u.second]){
            q.push(make_pair(abs(xy[u.second].y - xy[i].y), i));
        }

    }
    cout << ans << endl;
}
