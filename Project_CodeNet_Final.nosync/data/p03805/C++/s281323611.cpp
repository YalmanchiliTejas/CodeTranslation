#include<iostream>
#include<string.h>
#include<ctype.h>
#include<string>
#include<math.h>
#define pi 3.141592653589
#include<iomanip>
using namespace std;
#include<algorithm>

int root[8][8]={},pass[8]={},ans=0,cnt=0;

void deep(int x,int n){
    pass[x]=1;
    cnt++;
    for(int i=0;i<n;i++){
        if(cnt==n){
            ans++;
            break;
        }
        if(root[x][i]==1&&pass[i]==0){
            deep(i,n);
            cnt--;pass[i]=0;
        }
    }
}

int main(){
    
    int n,m,a,b;
    
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        root[a-1][b-1]=1;
        root[b-1][a-1]=1;
    }
    deep(0,n);
    cout<<ans<<endl;
    
    return 0;
}
 