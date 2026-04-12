#include <bits/stdc++.h>
using namespace std;
#define MD 1000000007
typedef long long int ll;

ll n,m,a[55];

ll dfs(ll x,ll y){//xはレベル，yは何層目か
    if(y<=x){//
        return 0;
    }else if(x==0){//レベル０はもちろん1枚しかないので
        return 1;
    }else{
        if(y-1<=a[x-1]){//層が左のx-1バーガーの範囲に収まった場合
            return dfs(x-1,y-1);
        }else if(y-1==a[x-1]+1){//層がちょうどxバーガーの真ん中の場合
            return dfs(x-1,a[x-1])+1;
        }else if(y!=a[x]){//層がxバーガー内部に収まった場合
            return dfs(x-1,a[x-1])+1+dfs(x-1,y-a[x-1]-2);
        }else{
            return dfs(x-1,a[x-1])*2+1;
        }
    }
}

int main(){
    cin>>n>>m;
    a[0]=1;
    for(int i=1;i<=n;i++){
        a[i]=a[i-1]*2+3;
    }
    cout<<dfs(n,m)<<endl;
    return 0;
}
    