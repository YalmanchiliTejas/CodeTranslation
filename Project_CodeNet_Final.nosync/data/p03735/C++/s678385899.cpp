#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;

using namespace std;

int n;
int cur[N];
pair < int, int > a[N];

long long solve()
{
        int res = 1e9;
        vector < pair < int, int > > v;
        for(int i = 1; i <= n; i++){
                v.push_back({a[i].fi, i});
                v.push_back({a[i].se, i});
        }
        sort(v.begin(), v.end());
        multiset < int > S;
        int cnt = 0;
        for(auto p: v){
                if(cur[p.se]){
                        S.erase(S.find(cur[p.se]));
                } else{
                        cnt += 1;
                }
                cur[p.se] = p.fi;
                S.insert(p.fi);
                if(cnt == n){
                        res = min(res, p.fi - *S.begin());
                }
        }
        return res;
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i].fi >> a[i].se;
                if(a[i].fi > a[i].se){
                        swap(a[i].fi, a[i].se);
                }
        }
        int A, B, C, D;
        A = B = a[1].fi;
        C = D = a[1].se;
        for(int i = 2; i <= n; i++){
                A = min(A, a[i].fi);
                B = max(B, a[i].fi);
                C = min(C, a[i].se);
                D = max(D, a[i].se);
        }
        long long res = (B - A) * 1ll * (D - C);

        cout << min(res, (D - A) * 1ll * solve()) << "\n";
}
