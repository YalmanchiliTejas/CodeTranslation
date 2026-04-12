#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int INF=1e9;

bool M[10][10];

int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        M[a][b]=true;
        M[b][a]=true;
    }
    int p[10];
    for(int i=0;i<n;i++){
        p[i]=i+1;
    }
    int ans=0;
    do{
        bool flag=true;
        for(int i=0;i<n-1;i++){
            if(!M[p[i]][p[i+1]]){
                flag=false;
                break;
            }
        }
        if(flag)ans++;
    }while(next_permutation(p+1,p+n));
    cout<<ans<<endl;
}
