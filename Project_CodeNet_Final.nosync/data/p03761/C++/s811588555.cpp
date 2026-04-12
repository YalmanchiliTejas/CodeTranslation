#include <bits/stdc++.h>
//#include <mylib.h>
using namespace std;
//cin.sync_with_stdio(false);

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define FOR_EQ(i,a,b) for(int i = (a); i <= (b); ++i)
#define FOR_RE(i,a,b) for(int i = (a); i > (b); --i)
#define rep(i,n) FOR(i,0,n)
#define rep_eq(i,n) FOR_EQ(i,0,n)
#define rep_re(i,n) FOR_RE(i,n,0)

#define WHITE 1//（未訪問）
#define GRAY 2//（訪問）未だに訪問していない頂点への辺を持っている。スタックに退避。
#define BLACK 3//（訪問完了）未訪問への頂点への辺を持たない
#define N 100
#define INFTY (1 << 21) //10^21
int M[N][N];//隣接行列
int color[N];

//1個上から時計周り
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
//上右下左
const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
static const int NIL = -1;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> Vector;
typedef vector<Vector>	DVector;
int n;

//配列の表示
void printArray(int array[], int n){
    rep(i, n){
        if(i)   cout << " ";
        cout << array[i];
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> n;
    int alp[n][26];
    string s[n];
    
    rep(i, n)   cin >> s[i];
    rep(i, n){
        rep(j, 26){
            alp[i][j] = 0;
        }
    }
    
    rep(i, n){
        int len = s[i].size();
        rep(j, len){
            alp[i][s[i][j] - 'a']++;
        }
    }
    
    int cnt;
    char tmp;
    rep(j, 26){
        cnt = INFTY;
        rep(i, n){
            cnt = min(cnt, alp[i][j]);
        }
        tmp = j + 'a';
        rep(k, cnt){
            cout << tmp;
        }
    }
    cout << endl;
}