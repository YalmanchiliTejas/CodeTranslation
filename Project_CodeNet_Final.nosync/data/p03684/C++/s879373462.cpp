#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using P = pair<int, int>;

int main(){
    int N;
    cin >> N;
    vector<P> x(N), y(N);
    vector<int> used(N, 0);
    for(int i = 0;i < N;i++){
        int a, b;
        cin >> a >> b;
        x[i] = P(a, i);
        y[i] = P(b, i);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    vector<vector<P>>   vp(N);
    int h[] = {1, -1};
    for(int i = 0;i < N;i++){
        for(int j = 0;j < 2;j++){
            int d = h[j];
            if(i+d >= 0 && i+d <= N-1){
                vp[x[i].second].push_back(P(abs(x[i].first-x[i+d].first), x[i+d].second));
                vp[y[i].second].push_back(P(abs(y[i].first-y[i+d].first), y[i+d].second));
            }
        }
    }
    priority_queue<P, vector<P>, greater<P>>  que;
    LL ans = 0;
    int count = 0;
    que.push(P(0, 0));
    while(count < N){
        P p = que.top();
        que.pop();
        int d = p.first;
        int v = p.second;
        if(used[v]) continue;
        used[v] = true;
        count++;
        ans += d;
        for(auto& itr : vp[v])  que.push(itr);
    }
    cout << ans << endl;
}