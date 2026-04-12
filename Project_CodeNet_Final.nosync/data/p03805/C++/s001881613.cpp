#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<bitset>
#include<utility>
#include<sstream>
#include<iomanip>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;

#define ll long long
#define MP make_pair
int n,m,num=0;
vector<vector<int>> e;

void dfs(int crtv,int nextv,vector<vector<int>> nowe,vector<int> nowv){

    nowe[crtv][nextv]=0;
    nowe[nextv][crtv]=0;

    bool jud=true;
    for (int i = 0; i < n; i++) {
        if(nowv[i]==0)jud=false;
    }
    if(jud){
        
        num++;
        return;
    }

    

    for (int i = 0; i < n; i++) {
        if(nowe[nextv][i]==1&&nowv[i]==0){
            nowv[i]=1;
            dfs(nextv,i,nowe,nowv);
            nowv[i]=0;
        }
    }





    return;
}

int main(void) {
    cin>>n>>m;
    int tn,tm;

    e.resize(n);
    for (int i = 0; i < e.size(); i++) {
        e[i].resize(n);
    }

    for (int i = 0; i < m; i++) {
        cin>>tn>>tm;
        e[tn-1][tm-1]=1;
        e[tm-1][tn-1]=1;
    }
    vector<int> v(n);
    v[0]=1;
    for (int i = 0; i < n; i++) {
        if(e[0][i]==1&&v[i]==0){
            v[i]=1;
            dfs(0,i,e,v);
            v[i]=0;
        }
    }

    cout<<num<<"\n";

    
    
    return 0;
}