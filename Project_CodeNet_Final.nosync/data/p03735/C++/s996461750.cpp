#include<bits/stdc++.h>
#define range(i,a,b) for(int i = (a); i < (b); i++)
#define rep(i,b) for(int i = 0; i < (b); i++)
#define all(a) (a).begin(), (a).end()
#define show(x)  cerr << #x << " = " << (x) << endl;
const long long INF = 1e15;
using namespace std;


int main(){
    int n;
    cin >> n;

    vector<pair<long long, long long>> v(n);
    long long mini = INF, maxi = 0;
    long long rmax = 0, bmin = INF;
    rep(i,n){
        cin >> v[i].first >> v[i].second;
        if(v[i].first > v[i].second) swap(v[i].first, v[i].second); //R min, B max
        mini = min(v[i].first, mini); //r min
        maxi = max(v[i].second, maxi); //b max
        rmax = max(v[i].first, rmax);
        bmin = min(v[i].second, bmin);
    }
    long long ans = (rmax - mini) * (maxi - bmin);
    sort(all(v));

    long long rmin = INF;
    rep(i,n - 1){
        rmax = max(v[i].second, rmax); //i番目をbと交換する
        rmin = min(v[i].second, rmin);
        ans = min(ans, (rmax - min(rmin, v[i + 1].first))*(maxi - mini));
    }
    cout << ans << endl;
}
