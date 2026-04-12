#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
using namespace std;
unsigned long long a[200001];
unsigned long long b[200001];
int main() {
    fastio
    int N;
    unsigned long long ans=0;
    cin>>N;
    for(int i=1;i<=N;i++)
        cin>>a[i];
    b[1]=a[1];
    for(int i=2;i<=N;i++){
        b[i]=a[i]+b[i-1];
    }
    for(int i=1;i<N;i++){
        ans+=((a[i]%1000000007)*((b[N]-b[i])%1000000007))%1000000007;
        ans%=1000000007;
    }
    cout<<ans;
    return 0;
}
