#include <cstdio>
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include <cmath>
#include <iomanip>
#include <regex>
#include <bits/stdc++.h>
#include <string>
using namespace std;
using ll = long long;
const ll MOD = 1000000007; 
int N,M;

int dfs(vector<vector<int>> v,vector<bool> reach,int now){
    reach[now] = true;
    bool flag_reach = true; 
    for(auto i=0;i<N;i++){
        if(!reach[i]){
            flag_reach=false;
        }
    }
    if(flag_reach) return 1;
    int sum = 0;
    for(long i=0;i<N;i++){
        if(v[now][i]==1&&!reach[i]){
            sum += dfs(v,reach,i);
        }
    }
    return sum;
}

int main(){   
    cin>>N>>M;
    vector<vector<int>> v(N,vector<int>(N,0));
    for(auto i=0;i<M;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        v[a][b] = 1;
        v[b][a] = 1;
    }
    vector<bool> reach(N,false);

    int res = dfs(v,reach,0);
    cout<<res<<endl;

}
