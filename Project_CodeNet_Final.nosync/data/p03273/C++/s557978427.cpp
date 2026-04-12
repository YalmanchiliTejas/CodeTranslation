#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i) = 0; (i) < (n); ++(i))
#define rrep(i,n) for(int (i) = (n) - 1; (i) >= 0; --(i)) //Reversi rep
#define nfor(i,a,b) for(int (i) = (a); (i) < (b); ++(i)) //Natural for
#define rfor(i,a,b) for(int (i) = (b); (i) >= (a); --(i)) //Reversi for
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
    int h,w;
    cin >> h >> w;
    string a[h];
    bool bh[h],bw[w];
    rep(i, h)cin >> a[i];
    rep(i, h)bh[i] = false;
    rep(i, w)bw[i] = false;
    rep(i, h){
        rep(j, w){
            if (a[i][j] == '#') {
                bh[i] = true;
            }
        }
    }
    
    rep(i, w){
        rep(j, h){
            if (a[j][i] == '#') {
                bw[i] = true;
            }
        }
    }
    
    rep(i, h){
        rep(j, w){
            if (bh[i] && bw[j]) {
                cout << a[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}
