#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    ll n,k;
    cin>>n>>k;
    ll res = 0;
    if(k==0) {
        cout<<n*n<<endl;
        return 0;
    }
    for (int b=k+1;b<=n;b++){
        res += (b-k)*(n/b) + max(n%b - k + 1,0LL);
    }
    cout<<res<<endl;
    return 0;
}
