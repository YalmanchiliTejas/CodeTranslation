#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#define rep(i,n) for(int (i) = 0;(i) < (n);(i)++)
#define SIZE 200005
#define INF 100000000000000000LL

using namespace std;
typedef long long int ll;
typedef pair <ll,int> P;

ll burger[51];
ll pati[51];


void init(){
    burger[0]=1;
    pati[0]=1;
    for(int i = 1;i <= 50;i++){
        burger[i] = burger[i-1]*2+3;
        pati[i] = pati[i-1]*2+1;
    }
}

ll dfs(ll level,ll X){//patiの数
    if(X==burger[level])
        return pati[level];
    if(X<0||X>burger[level]){
        return 0;
    }
    ll ret = 0;
    if(X>=1){
        X--;
    }else{return 0;}
    if(X>=burger[level-1]){
        X-=burger[level-1];
        ret += pati[level-1];
    }else{
        ret += dfs(level-1,X);
        return ret;
    }
    if(X>=1){
        X--;
        ret++;
    }else{
        return ret;
    }
    if(X>=burger[level-1]){
        X-=burger[level-1];
        ret += pati[level-1];
    }else{
        ret += dfs(level-1,X);
        return ret;
    }
    return ret;
}


int main(){
    ll N,X;
    cin>>N>>X;
    init();
    cout<<dfs(N,X)<<endl;
}
