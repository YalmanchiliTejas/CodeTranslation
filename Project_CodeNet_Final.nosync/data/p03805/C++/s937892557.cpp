#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    int p[n-1];
    for(int i=0;i<n-1;i++) p[i]=i+2;

    int a[m],b[m];
    for(int i=0;i<m;i++) cin>>a[i]>>b[i];

    int ans=0;
    do{
        int count=0;
        for(int j=0;j<m;j++){
            if(1==a[j]&&p[0]==b[j]) count++;
            else if(1==b[j]&&p[0]==a[j]) count++;
        }
        for(int i=0;i<n-2;i++){
            for(int j=0;j<m;j++){
                if(p[i]==a[j]&&p[i+1]==b[j]) count++;
                else if(p[i]==b[j]&&p[i+1]==a[j]) count++;
            }
        }
        if(count==n-1) ans++;
    }while(next_permutation(p,p+n-1));

    cout<<ans<<endl;
}