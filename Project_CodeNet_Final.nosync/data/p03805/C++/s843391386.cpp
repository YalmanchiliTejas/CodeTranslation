#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long unsigned int ll;


int main(){
    int ans=0;
    int n,m;
    int a[100],b[100];
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a[i]>>b[i];
    }
    int v[10];
    for(int i=0;i<n;i++){
        v[i]=i+1;
    }
    
    do{
        if(v[0]!=1){
            break;
        }
        int is[10]={0};//v[i]からv[i+1]へ辺があれば1
        for(int i=0;i<n-1;i++){
            //v[i]からv[i+1]にいく辺があるか探す
            for(int j=0;j<m;j++){
                if(v[i]==a[j]&&v[i+1]==b[j]){
                    is[i]=1;
                }else if(v[i]==b[j]&&v[i+1]==a[j]){
                    is[i]=1;
                }
            }
            
        
        }
        
        int c=1;
        for(int i=0;i<n-1;i++){
            c*=is[i];
        }
        
        if(c==1) ans++;
    }while(next_permutation(v,v+n));
    
    cout<<ans<<endl;
    return 0;
}
