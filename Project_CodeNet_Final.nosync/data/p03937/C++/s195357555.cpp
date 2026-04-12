#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define ALL(x) (x).begin(), (x).end()
#define REP(i ,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
typedef vector<int>vint;
typedef vector<ll>vll;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename A,typename B>inline bool chmin(A &a,const B &b){if(a>b){a=b;return true;}else{return false;}}
template<typename A,typename B>inline bool chmax(A &a,const B &b){if(a<b){a=b;return true;}else{return false;}}

int main()
{
    int H,W;
    cin >> H >> W;
    char A[H][W];
    REP(i,H){
        REP(j,W){
            cin >> A[i][j];
        }
    }
    int di[] = {0,1};
    int dj[] = {1,0};
    queue<pair<int,int>> que;
    if('#' == A[0][0]){
        A[0][0] = '.';
        que.push({0,0});
    }
    while(!que.empty()){
        auto p = que.front();
        que.pop();
        int i = p.first;
        int j = p.second;
        REP(dir,2){
            int ni = i + di[dir];
            int nj = j + dj[dir];
            if(ni >= H || nj >= W)continue;
            if('.' == A[ni][nj])continue;
            A[ni][nj] = '.';
            que.push({ni,nj});
            break;
        }
    }
    string ans = "Possible";
    REP(i,H){
        REP(j,W){
            if('#' == A[i][j]){
                ans = "Impossible";
            }
        }
    }
    cout << ans << endl;
}