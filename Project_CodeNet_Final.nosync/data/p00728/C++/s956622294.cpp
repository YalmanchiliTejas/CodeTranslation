#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb emplace_back
typedef long long ll;
typedef pair<int,int> pint;

int main(){
    int n;
    while(cin>>n,n){
        int mx=0,mn=1001,s;
        int sum=0;
        rep(i,n){
            cin>>s;
            sum+=s;
            mx=max(mx,s),mn=min(mn,s);
        }
        cout<<(sum-mx-mn)/(n-2)<<endl;
    }
    return 0;
}
