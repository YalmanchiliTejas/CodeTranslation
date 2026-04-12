#include <bits/stdc++.h>
using namespace std;
using lint = long long int;

int N;
vector<lint> x, y;

int main()
{
    cin >> N;
    x.resize(N);
    y.resize(N);
    lint min_=1000000000, max_=1;
    for (int i=0; i<N; i++)
    {
        cin >> x[i] >> y[i];
        if (x[i] > max_) max_ = x[i];
        if (y[i] > max_) max_ = y[i];
        if (x[i] < min_) min_ = x[i];
        if (y[i] < min_) min_ = y[i];
    }
    if (min_ == max_ )
    {
        cout << "0" << endl;
        return 0;
    }
    int tmp = 0;

    lint ans = (max_ - min_) * (max_ - min_);

    // 最大と最小が違う色になる場合
    {
        lint Rmax = max_;
        lint Rmin = max_;
        lint Bmax = min_;
        lint Bmin = min_;
        for (int i=0; i<N; i++)
        {
            Rmin = min(Rmin, max(x[i], y[i]));
            Bmax = max(Bmax, min(x[i], y[i]));
        }
        ans = min(ans, (Rmax-Rmin)*(Bmax-Bmin));
    }

    for (int i=0; i<N; i++)
    {
        if (x[i] == min_ || x[i] == max_ || y[i] == min_ || y[i] == max_) tmp++;
    }
    if (tmp > 1)
    {
        // 最小と最大が同じ色の場合
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>> >pq;
        lint max_tmp = 1;
        lint min___ = 1000000000;
        for (int i=0; i<N; i++)
        {
            pq.push(make_pair(min(x[i], y[i]), i));
            max_tmp = max(max_tmp, min(x[i], y[i]));
            min___ = min(min___, max(x[i], y[i]));
        }
        ans = min(ans, (max_-min_) * (max_ - min___));
        lint min_tmp = max_tmp;
        for (int i=0; i<N; i++)
        {
            // cout << i << " " << pq.top().first << " " << pq.top().second << " " << max_tmp << " " << endl;
            ans = min(ans, (max_tmp - min((lint)pq.top().first, min_tmp)) * (max_ - min_));
            int where = pq.top().second;
            max_tmp = max(max_tmp, max(x[where], y[where]));
            min_tmp = min(min_tmp, max(x[where], y[where]));
            pq.pop();
        }
    }
    cout << ans << endl;    
}