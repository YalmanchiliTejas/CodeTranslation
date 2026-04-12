#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector <int> > path(n, vector<int>(n,0));
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        path[a-1][b-1]=1;
        path[b-1][a-1]=1;
    }
    vector<int> order(n-1);
    for(int i=1;i<n;i++){
        order[i-1]=i;
    }
    int ans=0;
    do{
        int count=0;
        if (path[0][order[0]]==1) count++;
        else continue;
        for(int i=0;i<n-2;i++){
            if(path[order[i]][order[i+1]]==1)count++;
        }
        if(count==n-1) ans++;
    }while(next_permutation(order.begin(),order.end()));
    cout<<ans<<endl;
}