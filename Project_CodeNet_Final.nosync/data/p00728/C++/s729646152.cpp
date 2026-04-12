#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
#define MOD (1000000007)
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<int> res;
    while(1){
        int n;
        deque<int> rec;
        cin >> n;
        if(n == 0) break;
        for(int i=0;i<n;i++){
            int tmp;
            cin >> tmp;
            rec.push_back(tmp);
        }
        sort(rec.begin(), rec.end());
        rec.pop_front();
        rec.pop_back();
        int ans = 0;
        for(int i=0;i<n-2;i++){
            ans += rec[i];
        }
        res.push_back(ans/(n-2));
    }
    for(int i=0;i<res.size();i++) cout << res[i] << endl;
    return 0;
}
