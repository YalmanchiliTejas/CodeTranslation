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

int N;
ll X;
ll berger[55];  //bn = 2*bn-1 + 3   層の数
ll patti[55];   //an = 2*an-1 + 1   パティの数

ll pattiX(int N, ll X){
    if(X < 0 || N < 0){
        return 0;
    }else if(berger[N] / 2 < X){
        return patti[N] - pattiX(N-1, berger[N] - X - 1);
    }else{
        return pattiX(N-1, X-1);
    }
}

int main(){

    cin >> N >> X;

    patti[0] = 1; berger[0] = 1;
    for(int i = 1; i <= N; i++){
        patti[i] = patti[i-1] * 2 + 1;
        berger[i] = berger[i-1] * 2 + 3;
    }


    cout << pattiX(N, X) << endl;

    return 0;
}