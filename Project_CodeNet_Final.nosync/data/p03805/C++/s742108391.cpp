#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#define REP(i, N) for(int i = 0; i < N; ++i)
#define REEP(i, N) for(int i = N - 1; i >= 0; --i)
using namespace std;

int N, M, path;

void f(vector<vector<int>> &v, vector<int> p) {
    if(p.size() < N) {
        REP(i, N) {
            bool g = true;
            REP(j, p.size()) {
                if(p[j] == i + 1) {
                    g = false;
                    break;
                }
            }
            if(g) {
                vector<int> np(p.size() + 1);
                REP(k, p.size()) {
                    np[k] = p[k];
                }
                np[p.size()] = i + 1;
                f(v, np);
            }
        }
    }
    if(p.size() == N) {
        bool h = true;
        REP(i, N - 1) {
            if(v[p[i] - 1][p[i + 1] - 1] == 0) {
                h = false;
                break;
            }
        }
        if(h) ++path;
    }
    
}

int main(){
    cin >> N >> M;
    vector<vector<int>> v(N);
    REP(i, N) {
        v[i].resize(N);
        REP(j, N) {
            v[i][j] = 0;
        }
    }
    REP(i, M) {
        int a, b;
        cin >> a >> b;
        v[a - 1][b - 1] = v[b - 1][a - 1] = 1;
    }
    vector<int> p(1);
    p[0] = 1;
    f(v, p);
    cout << path << endl;

}
