#include<bits/stdc++.h>
using namespace std;
int a[10][10];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t,i,j,n,m,l,r,f,ans=0,c[10];
    cin>>n>>m;
    for(i=0;i<m;i++){
        cin>>l>>r;
        a[l][r]=1;
        a[r][l]=1;
    }
    for(i=0;i<n;i++){
        c[i]=i+1;
    }
    do{
        f=0;
        for(i=1;i<n;i++){
            if(a[c[i-1]][c[i]]==0){
                f=1;
                break;
            }
        }
        if(f==0){
            ans++;
        }
    }while(next_permutation(c+1,c+n));
    cout<<ans<<"\n";
    return 0;
}