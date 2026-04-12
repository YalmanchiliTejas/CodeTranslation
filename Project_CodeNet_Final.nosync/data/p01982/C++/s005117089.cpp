#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=ll(a); i<ll(b); i++)
#define rer(i,a,b) for(ll i=ll(a)-1; i>=ll(b); i--)

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(;;){
        int n,l,r;
        cin>>n>>l>>r;
        if(n==0) break;
        vector<int> a(n);
        rep(i,0,n) cin>>a[i];
        ll cnt=0;
        rep(x,l,r+1){
            rep(i,0,n){
                if(x%a[i]==0){
                    if(i%2==0){
                        cnt++;
                    }
                    break;
                }
                if(i==n-1&&n%2==0) cnt++;
            }
        }
        cout<<cnt<<"\n";
    }
}
