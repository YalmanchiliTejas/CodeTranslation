#include <bits/stdc++.h>
#define FOR(i, begin, end) for(int i=(begin);i<(end);i++)
#define REP(i, n) FOR(i,0,n)
#define IFOR(i, begin, end) for(int i=(end)-1;i>=(begin);i--)
#define IREP(i, n) IFOR(i,0,n)
#define SORT(a) sort(a.begin(), a.end())
#define REVERSE(a) reverse(a.begin(), a.end())
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
#define int long long
#define INF 1000000000000000000
using namespace std;

#define ANS(f) if(f) cout << "YES" << endl; else cout << "NO" << endl;

typedef vector<int> vec;
typedef vector<vec> mat;
typedef pair<int, int> Pii;

template<typename T>
void readv(vector<T> &a){ REP(i, a.size()) cin >> a[i]; }
void readi(vector<int> &a){ REP(i, a.size()){cin >> a[i]; a[i]--;} }
void debug(mat m){REP(i, m.size()){ REP(j, m[0].size()){ cout << m[i][j] << ","; } cout << endl; }}



signed main(){

    int A, B; cin >> A >> B;
    mat d(A, vec(B));
    REP(i, A) readv(d[i]);

    mat c(101, vec(101, 0));
    REP(i, A){
        REP(j, B){
            REP(Nx, 101) REP(Ny, 101){
                c[Nx][Ny] = max(c[Nx][Ny], d[i][j] - (i + 1) * Nx - (j + 1) * Ny);
            }
        }
    }

    REP(i, A){
        REP(j, B){
            int tmp = INF;
            REP(Nx, 101) REP(Ny, 101){
                tmp = min(tmp, (i + 1) * Nx + (j + 1) * Ny + c[Nx][Ny]);
            }
            if(tmp != d[i][j]){
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }

    cout << "Possible" << endl;
    cout << 202 << " " << 200 + 101 * 101 << endl;
    REP(i, 100) cout << i + 1 << " " << i + 2 << " X" << endl;
    REP(i, 100) cout << i + 102 << " " << i + 103 << " Y" << endl;
    REP(Nx, 101) REP(Ny, 101) cout << Nx + 1 << " " << 202 - Ny << " " << c[Nx][Ny] << endl;
    cout << "1 202" << endl;
    
    return 0;
}