#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include<bitset>
#include<math.h>
#include <string.h>
using namespace std;
#define INF 11000
#define MOD 1000000007
typedef long long ll;
typedef pair<int,int> P;

ll p[60];
ll num[60];
ll solve(int n,ll x){
    if(x==0) return 0;
    else if(n==0) return 1;
    else if(x<num[n-1]+2) return solve(n-1,x-1);
    else if(x==num[n-1]+2) return p[n-1]+1;
    else if(x<num[n-1]*2+3) return p[n-1]+1+solve(n-1,x-num[n-1]-2);
    else if(x==num[n-1]*2+3) return p[n-1]*2+1;
}

int main(){
    int N;
    ll X;
    cin>>N>>X;
    p[0]=1; num[0]=1;
    for(int i=1;i<=N;i++){
        p[i]=p[i-1]*2+1;
        num[i]=num[i-1]*2+3;
    }
    cout<<solve(N,X)<<endl;
}

