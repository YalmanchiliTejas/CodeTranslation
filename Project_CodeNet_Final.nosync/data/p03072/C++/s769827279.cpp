#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const ll N = 1e5 + 5, MOD = 1e9+7;

ll n,flag;
ll h[N],ans;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>n;
    for( ll i=1; i<=n; i++ )      cin>>h[i];

    for( ll i=1; i<=n; i++ ){
        flag=0;
        for( ll j=1; j<=i; j++ ){
            if(h[j]>h[i]){
                flag=1;
                break;
            }
        }
        if(!flag)    ans++;
    }
    cout<<ans<<endl;
    return 0;
}


