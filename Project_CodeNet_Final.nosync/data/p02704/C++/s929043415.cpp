#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int MAX_N = 510;

vector<int> S(MAX_N);
vector<int> T(MAX_N);
vector<ull> U(MAX_N);
vector<ull> V(MAX_N);
vector<vector<ull>> ANS(MAX_N, vector<ull>(MAX_N, 0ull));

int solve(int b, int n){
    // bit b
    // ok: return 1, false: return -1
    vector<vector<int>> ans(n, vector<int>(n, -1));
    // AND = 1, OR = 0
    for(int i=0;i<n;i++){
        // row
        ull u = U[i] >> b & 1;
        if(S[i]==0 && u==1){
            // all 1
            for(int j=0;j<n;j++){
                if(ans[i][j]!=-1 && ans[i][j]!=1){
                    return -1;
                }
                ans[i][j] = 1;
            }
        }else if(S[i]==1 && u==0){
            // all 0
            for(int j=0;j<n;j++){
                if(ans[i][j]!=-1 && ans[i][j]!=0){
                    return -1;
                }
                ans[i][j] = 0;
            }
        }
        // column
        ull v = V[i] >> b & 1;
        if(T[i]==0 && v==1){
            // all 1
            for(int j=0;j<n;j++){
                if(ans[j][i]!=-1 && ans[j][i]!=1){
                    return -1;
                }
                ans[j][i] = 1;
            }
        }else if(T[i]==1 && v==0){
            // all 0
            for(int j=0;j<n;j++){
                if(ans[j][i]!=-1 && ans[j][i]!=0){
                    return -1;
                }
                ans[j][i] = 0;
            }
        }
    }

    // same condition
    for(int i=0;i<n;i++){
        ull u = U[i] >> b & 1;
        if(S[i]==0 && u==1) continue;
        if(S[i]==1 && u==0) continue;
        for(int j=0;j<n;j++){
            ull v = V[j] >> b & 1;
            if(u==1 && v==1 && T[j]==1) ans[i][j] = 1;
            if(u==0 && v==0 && T[j]==0) ans[i][j] = 0;
        }
    }

    // set 0
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(ans[i][j]==-1) ans[i][j] = 0;
        }
    }

    // check at least one 0
    for(int i=0;i<n;i++){
        ull u = U[i] >> b & 1;
        if(S[i]==0 && u==0){
            bool ok = false;
            for(int j=0;j<n;j++){
                if(ans[i][j]==0){
                    ok = true;
                    break;
                }
            }
            if(!ok){
                return -1;
            }
        }
    }
    for(int j=0;j<n;j++){
        ull v = V[j] >> b & 1;
        if(T[j]==0 && v==0){
            bool ok = false;
            for(int i=0;i<n;i++){
                if(ans[i][j]==0){
                    ok = true;
                    break;
                }
            }
            if(!ok){
                return -1;
            }
        }
    }


    // check row and column, the conditiion of at least one 1
    for(int i=0;i<n;i++){
        ull u = U[i] >> b & 1;
        if(S[i]==0 && u==1) continue;
        if(u==0) continue;
        int want = 1;
        bool ok = false;
        for(int j=0;j<n;j++){
            if(ans[i][j]==want){
                ok = true;
                break;
            }
        }
        if(!ok){
            // select one column
            bool selected = false;
            for(int j=0;j<n;j++){
                ull v = V[j] >> b & 1;
                if(T[j]==0 && v==0){
                    bool able = false;
                    for(int k=0;k<n;k++){
                        if(k==i) continue;
                        if(ans[k][j] == 0){
                            able = true;
                        }
                    }
                    if(able){
                        ans[i][j] = 1;
                        selected = true;
                        break;
                    }
                }
            }
            if(!selected) return -1;
        }
    }

    for(int j=0;j<n;j++){
        ull v = V[j] >> b & 1;
        if(T[j]==0 && v==1) continue;
        if(v==0) continue;
        int want = 1;
        bool ok = false;
        for(int i=0;i<n;i++){
            if(ans[i][j]==want){
                ok = true;
                break;
            }
        }
        if(ok) continue;
        // select one column
        bool selected = false;
        for(int i=0;i<n;i++){
            ull u = U[i] >> b & 1;
            if(S[i]==0 && u==0){
                bool able = false;
                for(int k=0;k<n;k++){
                    if(k==j) continue;
                    if(ans[i][k] == 0){
                        able = true;
                    }
                }
                if(able){
                    ans[i][j] = 1;
                    selected = true;
                    break;
                }
            }
        }
        if(!selected) return -1;
    }

    // set ANS
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ANS[i][j] = ANS[i][j] | ull(ans[i][j]) << b;
        }
    }
    return 1;
}

int main(void)
{
    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> S.at(i);
    }
    for(int i=0;i<N;i++){
        cin >> T.at(i);
    }
    for(int i=0;i<N;i++){
        cin >> U.at(i);
    }
    for(int i=0;i<N;i++){
        cin >> V.at(i);
    }
    for(int i=0;i<=64;i++){
        int a = solve(i, N);
        if (a==-1){
            cout << -1 << endl;
            return 0;
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << ANS[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
