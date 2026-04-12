#include<bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    #ifdef lOCAL_EXEC
    #else
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #endif // lOCAL_EXEC
    long long int n,i,j,k,x,y,sum=0,m=1000000007;
    cin>>n;
    long long int A[n+1],suf[n+2]={0};
    for(i=1;i<=n;i++){
        cin>>A[i];
    }
    for(i=n;i>=1;i--){
        suf[i]=suf[i+1];
        suf[i]+=A[i];
    }
    for(i=1;i<=n;i++){
        sum+=(A[i]*(suf[i+1]%m))%m;
    }
    cout<<(sum+m)%m;
    return 0;
}
