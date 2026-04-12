#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;
ll mod = 1000000007;
ll inf = 1e18;
int main(){

    int n;
    ll x;
    cin >> n >> x;
    vector<ll> h(51),p(51);
    h[0]=1; p[0]=1;
    for(int i=1; i<=n; i++){
        h[i]=2*h[i-1]+3;
        p[i]=2*p[i-1]+1;
    }

    ll sum=0;
    while(true){
        if(x==h[n]){
            sum+=p[n];
            break;
        }else if(x>h[n-1]+1){
            sum+=p[n-1]+1;
            x-=h[n-1]+2;
            n--;
        }else{
            x--;
            n--;
        }
        // cout << n << ' ' << x << ' ' << sum << endl;
        if(n==0){
            if(x==1) sum++;
            break;
        }
    }
    cout << sum << endl;

    return 0;
}