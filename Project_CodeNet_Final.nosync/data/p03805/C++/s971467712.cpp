#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define all(x) (x).begin(),(x).end()
#define lla(x) (x).rbegin(),(x).rend()
#define rep(i, n) for (int i = 0; i < n; i++)
#define Rep(i, n) for (int i = 1; i <= n; i++)

int n, m, a, b, c[10][10]={}, ans = 0;

main(){
    scanf("%d%d", &n, &m);
    vi s(n);
    rep(i, n)s[i]=i;
    while(m--){
        scanf("%d%d", &a, &b);
        a--;b--;
        c[a][b]++;c[b][a]++;
    }
    do {
        bool flag = true;
        for(int i=1; i<n; i++){
            if(!c[s[i-1]][s[i]]) flag = false;
        }
        ans += flag;
    } while (next_permutation(s.begin()+1, s.end()));
    cout << ans << endl;
    return 0;
}