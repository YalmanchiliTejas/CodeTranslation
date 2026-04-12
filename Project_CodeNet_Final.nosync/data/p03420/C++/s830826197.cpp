#include<bits/stdc++.h>
using namespace std;
const int N=1e5+1;
int n,k;
long long ans;
int main(){
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for (int i=k;i<=n;i++){
        int x=n-i;
        int j=i+1;
        while (j<=n){
            int l;
            if (x/j==0)l=n;
            else
                l=x/((x/j));
            ans+=(x/j)*(l-j+1);
            j=l+1;
        }
        if (i)ans+=n-i;
    }
    cout<<ans;
    return 0;
}