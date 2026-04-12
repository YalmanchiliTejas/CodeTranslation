#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
template<typename T1,typename T2> bool chmin(T1 &a,T2 b){if(a<=b)return 0; a=b; return 1;}
template<typename T1,typename T2> bool chmax(T1 &a,T2 b){if(a>=b)return 0; a=b; return 1;}




signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
 
    int n;
    cin>>n;
    bool s[n],t[n];
    for(int i=0;i<n;i++)cin>>s[i];
    for(int i=0;i<n;i++)cin>>t[i];

    unsigned long long u[n],v[n];
    unsigned long long tu[n],tv[n];
    for(int i=0;i<n;i++){
        cin>>u[i];
        tu[i] = u[i];
    }
    for(int i=0;i<n;i++){
        cin>>v[i];
        tv[i] = v[i];
    }


    unsigned long long ans[n][n]={};
    int col[n][64]={};
    int row[n][64]={};

    // s[i]==0 or t[i]==0 の部分を先に作る。
    for(int i=0;i<n;i++){
        if(s[i] == 0){
            for(int j=0;j<n;j++){
                ans[i][j] |= u[i];
            }
        }
        if(t[i] == 0){
            for(int j=0;j<n;j++){
                ans[j][i] |= v[i];
            }
        }
    }

    // s[i]==1 && t[j]==1 -> u and v
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(s[i] && t[j]){
                unsigned long long ret = u[i] & v[j];
                ans[i][j] |= ret;
            }
        }
    }

    // 和集合で、もう完成しているのは消す
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(unsigned long long k=0;k<64;k++){
                if(ans[i][j] & (1ULL << k)){
                    row[i][k]++;
                    col[j][k]++;
                    if(s[i]==1 && (u[i] & (1ULL << k))){
                        u[i] -= (1ULL << k);
                    }
                    if(t[j]==1 && (v[j] & (1ULL << k))){
                        v[j] -= (1ULL << k);
                    }
                }
            }
        }
    }

    // 残り、和集合の足りない部分を、積のところで埋めるんやけど、積でその部分が1にならないようにしないといけない
    for(int i=0;i<n;i++){
        if(s[i] == 1){
            for(unsigned long long k=0;k<64;k++){
                if(u[i] & (1ULL<<k)){
                    int ma = 1e4;
                    for(int j=0;j<n;j++){
                        if(t[j]==0)chmin(ma,col[j][k]);
                    }
                    for(int j=0;j<n;j++){
                        if(t[j]==0 && ma==col[j][k]){
                            col[j][k]++;
                            row[i][k]++;
                            ans[i][j] |= (1ULL<<k);
                            u[i] -= (1ULL<<k);
                            break;
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        if(t[i] == 1){
            for(unsigned long long k=0;k<64;k++){
                if(v[i] & (1ULL<<k)){
                    int ma = 1e4;
                    for(int j=0;j<n;j++){
                        if(s[j]==0)chmin(ma,row[j][k]);
                    }
                    for(int j=0;j<n;j++){
                        if(s[j]==0 && ma==row[j][k]){
                            row[j][k]++;
                            col[i][k]++;
                            ans[j][i] |= (1ULL<<k);
                            v[i] -= (1ULL<<k);
                            break;
                        }
                    }
                }
            }
        }
    }


    // 最後に、tu, tvで条件を満たしているかチェック
    unsigned long long ru[n]={}, rv[n]={};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(s[i] == 0){
                if(j==0) ru[i] = ans[i][j];
                ru[i] &= ans[i][j];
            }
            else{
                ru[i] |= ans[i][j];
            }
            if(t[j] == 0){
                if(i==0) rv[j] = ans[i][j];
                rv[j] &= ans[i][j];
            }
            else{
                rv[j] |= ans[i][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        if((ru[i] != tu[i]) || (rv[i] != tv[i])){
            cout << -1 << endl;
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}
