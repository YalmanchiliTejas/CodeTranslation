#include "bits/stdc++.h"
using namespace std;
#define PB push_back
#define MP make_pair
#define REP(i,n) for(int i=0;i<(n);i++)
int main(){
    int n,m,a,b;
    cin>>n>>m;
    bool d[n][n];
    memset(d,false,sizeof(d));
    REP(i,m){
        cin>>a>>b;a--;b--;
        d[a][b]=d[b][a]=true;
    }
    vector<int> v;
    REP(i,n)v.PB(i);
    int ans=0;
    do{
        if(v[0]!=0)continue;
        bool f=true;
        for(int i=1;i<n;i++){
            if(!d[v[i]][v[i-1]])f=false;
        }
        if(f)ans++;
    }while(next_permutation(v.begin(),v.end()));
    cout<<ans<<endl;
}