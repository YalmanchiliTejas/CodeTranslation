#include <bits/stdc++.h>
#define ull unsigned long long
#define f first
#define s second
using namespace std;
const int inf=1e9;
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    ull f=1;
    int n;
    cin >> n;
    bool s[n],t[n];
    ull u[n],v[n],ans[n][n];
    for(int i=0;i<n;i++)cin >> s[i];
    for(int i=0;i<n;i++)cin >> t[i];
    for(int i=0;i<n;i++)cin >> u[i];
    for(int i=0;i<n;i++)cin >> v[i];
    memset(ans,0,sizeof ans);
    for(int k=0;k<64;k++){
        bool m[n][n],r[n]={0},c[n]={0},av[n][n];
        int rw[n]={0},cl[n]={0};
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                av[i][j]=0;
                bool p=(f<<k)&u[i];
                bool q=(f<<k)&v[j];
                p=p^s[i],q=q^t[j];
                if(p and q){
                    if(s[i]==t[j])m[i][j]=1^s[i],r[i]=1,c[j]=1;
                    else{
                        cout << -1;
                        return 0;
                    }
                }
                else if(p){
                    m[i][j]=1^s[i],r[i]=1;
                    if(m[i][j]==t[j])c[j]=1;
                }
                else if(q){
                    m[i][j]=1^t[j],c[j]=1;
                    if(m[i][j]==s[i])r[i]=1;
                }
                else{
                    if(s[i]==t[j])m[i][j]=s[i],r[i]=1,c[j]=1;
                    else rw[i]++,cl[j]++,av[i][j]=1;
                }
            }
        }
        while(1){
            int mr=inf,rn=n,mc=inf,cn=n;
            for(int i=0;i<n;i++){
                if(!r[i]){
                    if(rw[i]<mr)mr=rw[i],rn=i;
                }
                if(!c[i]){
                    if(cl[i]<mc)mc=cl[i],cn=i;
                }
            }
            if(rn==n and cn==n)break;
            if(mr==0 or mc==0){
                cout << -1;
                return 0;
            }
            if(mr<mc){
                r[rn]=1;
                for(int i=0;i<n;i++){
                    if(av[rn][i]){
                        m[rn][i]=s[rn];
                        av[rn][i]=0;
                        cl[i]--;
                        break;
                    }
                }
            }
            else{
                c[cn]=1;
                for(int i=0;i<n;i++){
                    if(av[i][cn]){
                        m[i][cn]=t[cn];
                        av[i][cn]=0;
                        rw[i]--;
                        break;
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(m[i][j])ans[i][j]+=(f<<k);
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout << ans[i][j] <<  " ";
        cout << '\n';
    }
}