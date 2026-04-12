#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF = 100000000;

ll i,j,k;
vector<ll> a,p;//a:層数　p:パティ数

ll hamburger(ll level,ll x){//探索しているlevel
    if(level==0){
        if(x<=0){return 0;}
        else{return 1;}
    }
    
    if(x<=1+a[level-1]){//xが(下のバン+level内に含まれるlevel-1のlayer数)以下の時
        return hamburger(level-1,x-1);//一つ下のlevelへ(xもバン1つ分減る)
    }
    else{
        return p[level-1]+1+hamburger(level-1,x-2-a[level-1]);
        //level-1に収まらないとき:level-1を完全に含むので、(そのパティ数+真ん中のパティ)+向かいのlevel-1の探索
    }
}

int main(){
    ll n,x;cin>>n>>x;
    a.resize(n+1);p.resize(n+1);
    a[0]=p[0]=1;
    for(i=0;i<n;i++){
        a[i+1]=a[i]*2+3;//level iの層数
        p[i+1]=p[i]*2+1;//level iのパティ数
    }

    cout<<hamburger(n,x)<<endl;
    return 0;
}