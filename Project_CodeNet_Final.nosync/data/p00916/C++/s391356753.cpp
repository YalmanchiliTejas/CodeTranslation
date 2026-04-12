#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N;
vector<int> L, T, R, B;
vector<int> X, Y;
vector<vector<ll>> field;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void compress(vector<int> &X){
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
}

void dfs(int x, int y){
    ll val = field[x][y];
    field[x][y] = -1;
    
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0<=nx && nx<X.size() && 0<=ny && ny<Y.size() && field[nx][ny] == val){
            dfs(nx, ny);
        }
    }
}

int main(){
    while(cin >> N, N){
        L.resize(N); T.resize(N); R.resize(N); B.resize(N);
        
        X.clear(); Y.clear();
        for(int i=0; i<N; i++){
            cin >> L[i] >> T[i] >> R[i] >> B[i];
            for(int j=-1; j<=1; j++){
                X.push_back(L[i] + j);
                X.push_back(R[i] + j);
                Y.push_back(T[i] + j);
                Y.push_back(B[i] + j);
            }
        }
        compress(X); compress(Y);
        
        field = vector<vector<ll>>(X.size(), vector<ll>(Y.size()));
        for(int i=0; i<X.size(); i++){
            for(int j=0; j<Y.size(); j++){
                ll t = 0;
                for(int k=0; k<N; k++){
                    if(L[k]<=X[i] && X[i]<R[k] && B[k]<=Y[j] && Y[j]<T[k])
                        t |= 1LL<<k;
                }
                field[i][j] = t;
            }
        }
        
        int ans = 0;
        for(int i=0; i<X.size(); i++){
            for(int j=0; j<Y.size(); j++) if(field[i][j] >= 0){
                dfs(i, j);
                ans++;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}