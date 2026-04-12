#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
//long long mo = 1e9 + 7;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    string N;
    int K;
    cin >> N >> K;
    if(N.size() < K){
        cout << 0 << endl;
        return 0;
    }
    int L = N.size();
    vector<vector<vector<int>>> DP(L+1,vector<vector<int>> (K+1, vector<int>(2,0)));
    DP[0][0][0] = 1;

    rep(i,L){
        rep(j,K+1){
            rep(m,2){
                int nd = N[i] - '0';
                rep(d,10){
                    int cm = m, cj = j;
                    if(m == 1){
                        if(d != 0){
                            cj++;
                        }
                        if(cj > K){
                            continue;
                        }

                    }else{
                        if(d > nd){
                            continue;
                        }
                        if(d != 0){
                            cj++;
                        }
                        if(d != nd){
                            cm = 1;
                        }
                        if(cj > K){
                            continue;
                        }
                    }
                    DP[i+1][cj][cm] += DP[i][j][m];
                }
            }
        }
    }
    cout << DP[L][K][0] + DP[L][K][1] << endl;
    /*
    ll tot=0;
    if(K == 1){
        tot += 9*(L-1);
        tot += N[0] - '0'; 
    }else if(K == 2){
        tot += 9*9*(L-1)*(L-2);
        ll tmp = 1;
        rep(i,L){
            if(N[i] == '0') continue;
            if(N[i] - '0' - 1 > 0 && L-i-1 >0){
                tmp *= ((N[i] - '0')-1)*9*(L-i-1);
            }else if(){
                int j=1;
                while(j < L){
                    if(N[j] == '0'){
                        j++
                        continue;
                    }else if()
                }
            }

        }
        tot += tmp;
    }else{
        tot += 9*9*9*(L-1)*(L-2)*(L-3);
        ll tmp = 1;
        rep(i,L){
            //tot += (N[0] - '0')*9*9*(L-1)*(L-2);
            tmp *= (N[i] - '0')*(L-i-1)*9;
        }
        tot += tmp;
    }
    cout<< tot <<endl;*/
}
