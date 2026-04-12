#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n,m,ans=0;
bool used[10];
int perm[10],a[50],b[50];

bool che(int x,int y){
    for(int i=0;i<m;i++){
        if(a[i]==x&&b[i]==y)return true;
        if(a[i]==y&&b[i]==x)return true;
    }
    return false;
}

void solve(){
    bool res=true;
    for(int i=0;i<n-1;i++){
        int x=perm[i],y=perm[i+1];
        if(!che(x,y))res=false;
    }
    if(res)ans++;
}

void permutation1(int pos,int n){
    if(pos==n){
        if(perm[0]==1)solve();
        return ;
    }
    
    for(int i=0;i<n;i++){
        if(!used[i]){
            perm[pos]=i+1;
            used[i]=true;
            permutation1(pos+1,n);
            used[i]=false;
        }
    }
    return ;
}

int main(void){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a[i]>>b[i];
    }
    permutation1(0,n);
    cout<<ans<<endl;
    return 0;
}
