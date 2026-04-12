#include <iostream>
#include<map>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#define INF 1e16
#define rep(i,n) for(int i=0;i<n;i++)
#define NO cout<<"NO"<<endl;
#define YES cout << "YES"<<endl;
#define No cout << "No"<<endl;
#define Yes cout << "Yes"<<endl;
#define all(a) a.begin(),a.end()
#define P pair<ll,ll>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

//(int)'a'は97 (int)'A'は65 (int)'1'は49
//おまじない
//UnionFind

const int maxn=100000;

ll n,x;
ll p[51],sum[51];

ll cal(ll n,ll x){
    if(x==1){
        return (n>0)? 0:1;
    }else if(1<x&&x<2+sum[n-1]){
        return cal(n-1,x-1);
    }else if(x==2+sum[n-1]){
        return 1+p[n-1];
    }else if(2+sum[n-1]<x&&x<2*sum[n-1]+3){
        return p[n-1]+1+cal(n-1,x-2-sum[n-1]);
    }else if(x==2*sum[n-1]+3){
        return 2*p[n-1]+1;
    }
    
    return 0;
}

int main(){
    
    
    cin >> n>>x;
    p[0]=1;
    sum[0]=1;
    for(int i=1;i<=n;i++){
        p[i]=2*p[i-1]+1;
        sum[i]=sum[i-1]*2+3;
    }
    
    cout << cal(n,x)<<endl;
    
    return 0;
}
