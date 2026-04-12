#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;
//typedef pair<int,int> P;
//int const INF=1001001001;
//ll const INF=1001001001001001001;
ll const MOD=1000000007;

int N,M;

int main(){
    cin>>N>>M;
    vector<vector<int>> v(N);
    rep(i,M){
        int a,b;
        cin>>a>>b;
        v[a-1].push_back(b-1);
        v[b-1].push_back(a-1);
    }

    int table[8];
    rep(i,8) table[i]=i;
    int ans=0;
    do{
        rep(i,N-1){
            bool flag=false;
            rep(j,v[table[i]].size()){
                if(v[table[i]][j]==table[i+1]) flag=true; 
            }
            if(!flag) goto a;
        }
        ans++;
        a:;
    }while(next_permutation(table+1,table+N));

    cout<<ans<<endl;
}