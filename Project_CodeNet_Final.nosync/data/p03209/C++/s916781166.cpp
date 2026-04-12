#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define int long long
#define double long double
#define mod 1000000007
#define F first
#define S second
#define P pair<long long,long long>
#define all(a) a.begin(),a.end()
#define INF 1000000000000000000
using namespace std;
int num[55]={1},pat[50]={1};
int cnt_patty(int n, int x){
    if(x==1){
        if(n==0) return 1;
        else return 0;
    }
    if(x<=num[n-1]+1) return cnt_patty(n-1, x-1);
    if(x==num[n-1]+2) return cnt_patty(n-1, x-1)+1;
    else return cnt_patty(n-1, x-num[n-1]-2)+pat[n-1]+1;
}
signed main(){
    int n,x; cin>>n>>x;
    for(int i=1; i<=n; i++){
        num[i]=num[i-1]*2+3;
        pat[i]=pat[i-1]*2+1;
    }
    cout<<cnt_patty(n, x)<<endl;
}