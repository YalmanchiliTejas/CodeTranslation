#include <iostream>
using namespace std;

int N,M;
bool A[8][8] = {0};
bool V[8] = {0};
int ans = 0;

void dfs(int s) {
    bool flag = true;
    for(int i=0; i<N; ++i) {
        if(V[i] == false) {
            flag = false;
            break;
        }
    }
    if(flag) {
        ++ans;
        return;
    }
    for(int i=0; i<N; ++i) {
        if(A[s][i] == true && V[i] == false) {
            V[i] = true;
            dfs(i);
            V[i] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    int a,b;
    for(int i=0; i<M; ++i) {
        cin >> a >> b;
        A[a-1][b-1] = A[b-1][a-1] = true;
    }
    V[0] = true;
    dfs(0);
    cout << ans << endl;
}