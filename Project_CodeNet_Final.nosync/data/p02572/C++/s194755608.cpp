#include<bits/stdc++.h>
using namespace std;

#define Bye return 0
#define ll long long
const ll M = 1e9+7;
const ll SIZE = 2e5+1;
vector<ll> ps(SIZE, 0); 
int e, n;
ll res = 0;

int scan(){
    scanf("%d", &e);
    return e;
}

void solve(){
    cin>>n;
    for (int i=1; i<=n; i++){
        ps[i] = (ps[i-1] + scan()*1ll)%M;
        res = (res%M + (e*ps[i-1])%M)%M;
    }
    cout<<res<<endl;
}

int main(){
    solve();
    Bye;
}