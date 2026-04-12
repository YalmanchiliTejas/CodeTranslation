#include<math.h>
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)n; i++)
using namespace std;

int main(void) {
    int n,ans=1;
    cin>>n;
    vector<int> h(n);
    rep(i,n){cin>>h[i];}
    for(int i=1;i<n+1;i++)
    {
        if(h[0]<=h[0+i]){
            ans++;
            h[0]=h[0+i];
        }
    }
    cout<<ans<<endl;
}
