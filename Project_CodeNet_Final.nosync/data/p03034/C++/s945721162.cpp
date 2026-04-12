#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

int n;
int s[100001];
int main(){
    cin>>n;
    rep(i,n) cin>>s[i];
    ll mx=0;
    FOR(c,1,n){
        int l=0,r=n-1;
        ll sum=0;
        rep(k,(n+c-1)/c){
            l+=c;r-=c;
            if(l>n-1||r<c||(r%c==0&&r<=l)) break;
            sum+=s[l]+s[r];
            mx=max(mx,sum);
        }
    }
    cout<<mx<<endl;
    return 0;
}
