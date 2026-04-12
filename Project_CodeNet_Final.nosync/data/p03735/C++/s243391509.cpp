#include<bits/stdc++.h>
using namespace std;

using i64 = long long int;

int main(){
    int n;
    cin >> n;
    vector<i64> x, y;
    pair<i64, int> maxi = make_pair(0, 0), mini = make_pair(1000000001, 0);
    priority_queue<pair<i64, int>, vector<pair<i64, int>>, greater<pair<i64, int>>> blue;
    for(int i=0;i<n;++i){
        i64 xi, yi;
        cin >> xi >> yi;
        x.push_back(xi);
        y.push_back(yi);
        maxi = max({maxi, make_pair(xi, i), make_pair(yi, i)});
        mini = min({mini, make_pair(xi, i), make_pair(yi, i)});
        blue.push(make_pair(min(xi, yi), i));
    }

    pair<i64, int> rmin = maxi, bmax = mini;
    for(int i=0;i<n;++i){
        rmin = min(rmin, max(make_pair(x[i], i), make_pair(y[i], i)));
        bmax = max(bmax, min(make_pair(x[i], i), make_pair(y[i], i)));
    }
    i64 ans = (maxi.first - rmin.first) * (bmax.first - mini.first);

    if(maxi.second != mini.second){
        for(int i=0;i<n;++i){
            auto p = blue.top(); blue.pop();
            auto new_blue = make_pair(max(x[p.second], y[p.second]), p.second);
            blue.push(new_blue);
            bmax = max(bmax, new_blue);
            ans = min(ans, (maxi.first - mini.first) * (bmax.first - blue.top().first));
        }
    }

    cout << ans << endl;

    return 0;
}
