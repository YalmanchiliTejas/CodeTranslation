#include<iostream>
#include<algorithm>
#include<stdlib.h>
#include<iomanip>
#include<string>
#include<math.h>
#define MOD 1000000007

bool graph[8][8];
using namespace std; 
int main(){
    int ans=0;
    int path[8];
    int n,m;
    int a,b;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        a--;b--;
        graph[a][b]=true;
        graph[b][a]=true;
    }
    for(int i=0;i<n;i++){
        path[i]=i;
    }
    do{
        bool flag=true;
        for(int i=0;i<n-1;i++){
            if(!graph[path[i]][path[i+1]])flag=false;
        }
        if(flag)ans++;
    }while(next_permutation(path+1,path+n));
    cout<<ans<<endl;
    return 0;
}
