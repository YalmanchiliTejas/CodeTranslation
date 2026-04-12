#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <iomanip>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define FOR(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define All(v) (v).begin(),(v).end()
typedef long long ll;

ll a[51],p[51];

ll rec(ll n,ll x){
    if(n==0)return 1;
    if(x==1)return 0;
    else if(x<=a[n-1]+1)return rec(n-1,x-1);
    else if(x==a[n-1]+2)return p[n-1]+1;
    else return p[n-1]+1+rec(n-1,x-(a[n-1]+2));
}

int main(){
    ll N,X;cin >> N >> X;
    a[0]=1;p[0]=1;
    for(int i=0;i<=N;i++){
        a[i+1]=2*a[i]+3;
        p[i+1]=2*p[i]+1;
    }

    cout << rec(N,X) << endl;
    return 0;
}