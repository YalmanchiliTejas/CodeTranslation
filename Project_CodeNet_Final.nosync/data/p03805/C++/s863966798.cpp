#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[m],b[m];
    int dist[n][n]={};
    for(int i=0;i<m;i++){
        cin>>a[i]>>b[i];
        dist[a[i]-1][b[i]-1]=1;
        dist[b[i]-1][a[i]-1]=1;
    }
    int x[n];
    for(int i=0;i<n;i++)x[i]=i;
    int ans=0;
    do{
        for(int i=0;i<n-1;i++){
            if(dist[x[i]][x[i+1]]!=1){
                ans--;
                break;
            }
        }
        ans++;
    }while(next_permutation(x+1,x+n));
    cout<<ans<<endl;
    return 0;
}