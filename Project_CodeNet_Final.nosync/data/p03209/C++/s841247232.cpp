/**
2018/12/08/ 未完成
2018/12/11/ 解説AC
再帰関数の書き方。場合分けをしっかり考える
**/
#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()

inline int toInt(string s) {int v; istringstream sin(s);sin>>v; return v;}

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector< vector<int> > Mat;
typedef tuple<int, int, int, int> T;

const int MOD = (int)1e9+7;
const int INF = (int)1e9;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ddx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const int ddy[] = {1, 1, 0, -1, -1, -1, 0, 1};

ll berger[55];  //bn = 2*bn-1 + 3   層の数(パティ+バン)
ll patti[55];   //an = 2*an-1 + 1   パティの数

int N;
ll X;

ll pattiX(int N, ll X){
    
    if(N == 0){
        if(X <= 0) return 0;
        else return 1;
    }
    
    //if(N < 0 || X < 0) return 0;
    //else if(X == 2 + berger[N-1]) return patti[N-1] + 1;
    //else if(X == 3 + 2*berger[N-1]) return 2*patti[N-1] + 1;
    else if(X <= 1 + berger[N-1])return pattiX(N-1, X-1);
    else return patti[N-1] + 1 + pattiX(N-1, X - 2 - berger[N-1]);  //(X <= 2 + 2*berger[N-1])
}


int main(){

    cin >> N >> X;

    berger[0] = 1; patti[0] = 1;
    for(int i = 1; i <= N; i++){
        berger[i] = 2*berger[i-1] + 3;
        patti[i] = 2*patti[i-1] + 1;
    }

    cout << pattiX(N, X) << endl;

    return 0;
}