#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;  cin>>n;
    int a[n+1];   for(int i=0;i<=n;i++)a[i]=0;
    int minx=101;
    for(int i=1;i<=n;i++){
        int x;  cin>>x;
        for(int j=i;j<=n;j++){
            a[j]+=x;
        }
    }

    int ans=101;

    for(int i=1;i<n;i++){
        if(ans>a[i]/i)ans=a[i]/i;
    }
    cout<<ans<<endl;

    return 0;
}

