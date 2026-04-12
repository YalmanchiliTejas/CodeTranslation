#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int mod = 1e9 + 7;

using namespace std;

int n;
int x[N];
int y[N];
int p[N];

int get(int x) { return x == p[x] ? x : p[x] = get(p[x]); }

vector < pair < int, pair < int, int > > > edge;

void add_edge(int i, int h)
{
        int dist = min(abs(x[i] - x[h]), abs(y[i] - y[h]));
        edge.push_back({dist, {i, h}});
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n;
        vector < pair < int, int > > A, B;
        for(int i = 1; i <= n; i++){
                cin >> x[i] >> y[i];
                p[i] = i;
                A.push_back({x[i], i});
                B.push_back({y[i], i});
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        for(int i = 1; i < n; i++){
                add_edge(A[i - 1].se, A[i].se);
                add_edge(B[i - 1].se, B[i].se);
        }
        sort(edge.begin(), edge.end());
        long long res = 0;
        for(auto q: edge){
                int x = get(q.se.fi), y = get(q.se.se);
                if(x != y){
                        p[x] = y;
                        res += q.fi;
                }
        }
        cout << res << "\n";
}
