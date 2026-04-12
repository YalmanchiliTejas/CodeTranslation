#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i) = 0; (i) < (n); ++(i))
#define rrep(i,n) for(int (i) = (n) - 1; (i) >= 0; --(i)) //Reversi rep
#define nfor(i,a,b) for(int (i) = (a); (i) < (b); ++(i)) //Natural for
#define rfor(i,a,b) for(int (i) = (b) - 1; (i) >= (a); --(i)) //Reversi for
#define ll long long
#define mod (1000000007)
#define YES cout << "YES" << endl;
#define Yes cout << "Yes" << endl;
#define yes cout << "yes" << endl;
#define NO cout << "NO" << endl;
#define No cout << "No" << endl;
#define no cout << "no" << endl;

int asc(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

int desc(const void *a, const void *b) {
    return *(int *)b - *(int *)a;
}

int main()
{
    int h,w,cnt = 0,b = 0,c = 0;
    cin >> h >> w;
    string a[h];
    rep(i, h)cin >> a[i];
    rep(i, h)rep(j, w)if(a[i][j] == '#')++cnt;
    if (cnt != h + w - 1) {
        cout << "Impossible" << endl;
        //cout << 1 << endl;
    }else{
        if (a[b][c] != '#') {
            cout << "Impossible" << endl;
            cout << 2 << endl;
        }else{
            rep(i, h + w - 2){
                if ((a[b + 1][c] != '#' && a[b][c + 1] != '#') || (a[b + 1][c] == '#' && a[b][c + 1] == '#')) {
                    cout << "Impossible" << endl;
                    return 0;
                }else if (a[b + 1][c] == '#' && a[b][c + 1] != '#'){
                    ++b;
                }else if (a[b + 1][c] != '#' && a[b][c + 1] == '#'){
                    ++c;
                }
            }
            cout << "Possible" << endl;
        }
    }
    return 0;
}
