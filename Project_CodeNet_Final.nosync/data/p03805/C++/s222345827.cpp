#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,m;
    int a,b;
    int ans=0;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(n,0));
    vector<int> v(n);
    iota(v.begin(),v.end(),0);
    for(int i=0;i<m;i++){
        cin>>a>>b;
        matrix[a-1][b-1]=1;
        matrix[b-1][a-1]=1;
    }
    int i;
    do{
        if(v[0]!=0) continue;
        for(i=0;i<n-1;i++){
            if(matrix[v[i]][v[i+1]]!=1){
                break;
            }
        }
        if(i==n-1){
            ans++;
        }
    }while(next_permutation(v.begin(),v.end()));
    cout<<ans<<endl;
}
