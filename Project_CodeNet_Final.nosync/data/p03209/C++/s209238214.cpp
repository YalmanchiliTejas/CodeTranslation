#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

ll n,x;
ll a[50+1],p[50+1];

ll solve(ll n, ll x){
    if(n==0){
        if(x<=0) return 0;
        else return 1;
    }else if(x<=a[n-1]+1){
        return solve(n-1,x-1);
    }else{
        return p[n-1]+1+solve(n-1,x-2-a[n-1]);
    }
}

int main(){
    cin >> n >> x;
    a[0]=p[0]=1;
    for(ll i=1;i<=n;i++){
        a[i]=2*a[i-1]+3;
        p[i]=2*p[i-1]+1;
    }
    cout << solve(n,x) << endl;
}