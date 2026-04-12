#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<pair<ll,ll>> ball;
    ll Max=0,Min=1e9;
    for (int i=0;i<N;++i){
        ll x,y; cin >> x >> y;
        ball.emplace_back(minmax(x,y));
        Max=max(Max,max(x,y));
        Min=min(Min,max(x,y));
    }
    sort(ball.begin(),ball.end());
    ll ans=(ball[N-1].first-ball[0].first)*(Max-Min);
    Max=max(Max,ball[N-1].first);
    Min=min(Min,ball[0].first);
    set<pair<ll,int>> red;
    red.emplace(ball[0].second,-1);
    for (int i=1;i<N;++i) red.emplace(ball[i].second,i);
    while(1){
        ans=min(ans,(red.rbegin()->first-red.begin()->first)*(Max-Min));
        auto nxt=*red.rbegin();
        red.erase(nxt);
        if (nxt.second==-1) break;
        red.emplace(ball[nxt.second].first,-1);
    }
    cout << ans << '\n';
}