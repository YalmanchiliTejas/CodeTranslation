#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long int i=0;i<n;++i)
typedef long long int ll;

int main(){

    while(1){
        int n,l,r;
        cin >> n >> l >> r;
        if(n==0)break;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        int ans=0;
        for(int i=l;i<=r;i++){
            for(int j=0;j<=n;j++){
                if(j==n){
                    if(n%2==0)ans++;
                    break;
                }
                if(i%a[j]==0){
                    if(j%2==0){
                        ans++;
                    }
                    break;
                }
            }
        }
        cout << ans << endl;
    }

    return 0;
}
