#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<long long> x(N), y(N);
    for(int i=0; i<N; i++) {
        cin >> x[i] >> y[i];
        if(x[i] > y[i]) swap(x[i], y[i]);
    }

    long long xmax = *max_element(x.begin(), x.end());
    long long xmin = *min_element(x.begin(), x.end());
    long long ymax = *max_element(y.begin(), y.end());
    long long ymin = *min_element(y.begin(), y.end());

    long long ans = (xmax - xmin) * (ymax - ymin);

    long long dif1 = ymax - xmin;

    vector<pair<long long, long long>> xy(N);
    for(int i=0; i<N; i++) xy[i] = pair<long long, long long>(x[i], y[i]);
    sort(xy.begin(), xy.end());

    multiset<long long> ms;
    for(int i=0; i<N; i++) ms.insert(xy[i].first);

    long long dif2 = *ms.rbegin() - *ms.begin();
    for(int i=0; i<N; i++){
        auto itr = ms.find(xy[i].first);
        ms.erase(itr);
        ms.insert(xy[i].second);
        dif2 = min(dif2, *ms.rbegin() - *ms.begin());
    }
    ans = min(ans, dif1 * dif2);

    cout << ans << endl;
    return 0;
}