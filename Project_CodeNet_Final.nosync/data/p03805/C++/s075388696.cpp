#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    int n,m,x[8],c=0;
    bool e[9][9];
    cin>>n>>m;
    for(int i=0;i<9;i++)for(int j=0;j<9;j++)e[i][j]=false;
    for(int i=0;i<n;i++)x[i]=i+1;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        e[a][b]=e[b][a]=true;
    }
    do{
        /*
        for(int i=0;i<n;i++){
            cout<<x[i];
            if(i<n-1)cout<<" ";
            else cout<<endl;
        }
        */
        bool f=true;
        for(int i=0;i<n-1&&f;i++){
            f=e[x[i]][x[i+1]];
        }
        if(f)c++;
    }while(next_permutation(x+1,x+n));
    
    cout<<c<<endl;
}
