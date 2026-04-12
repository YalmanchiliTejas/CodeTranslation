#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define st first
#define nd second
typedef pair < int , int > pp;
const int mod = 1e9 + 7;
const int N   = 1e2 + 2;

set < pp > S;
set < pp > :: iterator it; 
int A[11][11],M[N][N],m,n,i,j,k,l,kk,ll,x,mn;

signed main(){
    cin >> m >> n;
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++){
            cin >> x;
            A[i][j] = x;
            for(k=0;k<N;k++)
                for(l=0;l<N;l++)
                    M[k][l] = max(M[k][l] , x - i*k - j*l);
        }
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++){
            mn = mod;
            for(k=0;k<N;k++)
                for(l=0;l<N;l++)
                    if(mn > (x = i*k + j*l + M[k][l])){
                        mn = x;
                        kk = k;
                        ll = l;
                    }
        
            if(mn != A[i][j]){
                puts("Impossible");
                return 0;
            }
            S.insert(mp(kk,ll));
        }
        
    puts("Possible");
    printf("%d %d\n", N+N, N+N-2+(int)S.size());
    for(i=1;i<N;i++) printf("%d %d X\n", i, i+1);
    for(i++;i<N+N;i++) printf("%d %d Y\n", i, i+1);
    
    for(it=S.begin();it!=S.end();it++)
        printf("%d %d %d\n", it->st + 1, N+N - it->nd, M[it->st][it->nd]);
    
    printf("1 %d\n",N+N);
    return 0;
}