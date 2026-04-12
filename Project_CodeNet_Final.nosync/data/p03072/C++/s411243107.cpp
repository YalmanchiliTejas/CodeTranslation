#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int h[25];
int m;
int ans;
int main(void){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>h[i];
        if(h[i]>=m) ans++;
        m=max(m,h[i]);
    }
    cout<<ans<<endl;

}

