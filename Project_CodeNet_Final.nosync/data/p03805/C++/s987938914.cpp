#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);i++)
using namespace std;
#define int long long 
signed main(void){
    int N,M;
    int Ans=0;
    bool c=0;
    int a[60],b[60];
    bool hen[10][10]={};
    vector<int> V={1,2,3,4,5,6,7,8};
    cin >> N >> M;
    REP(i,M){
        cin >> a[i] >> b[i];
        hen[a[i]][b[i]]=1;
        hen[b[i]][a[i]]=1;
    }
    
    do {
        //REP(i,N)cout << V[i] << " ";
        //cout << endl;
        c=0;
        REP(i,N-1){
            if(hen[V[i]][V[i+1]]==0 && hen[V[i+1]][V[i]]==0){
                c=1;
            }
        }
        if(c==0){Ans++;}
    } while (next_permutation(V.begin()+1, V.begin()+N));
    cout << Ans << endl;
    return 0;
}
