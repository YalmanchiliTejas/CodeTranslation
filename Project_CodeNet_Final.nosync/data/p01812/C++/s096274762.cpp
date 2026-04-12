#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cstdio>
#include <ctime>
#include <assert.h>
#include <chrono>
#include <random>
#include <numeric>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
using namespace std;
typedef long long int ll;
typedef unsigned long long ull;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m,k; cin >> n >> m >> k;
    vector<int> a(m);
    vector<int> mp(n,-1);
    //map<int,int>> mp;
    for(int i=0;i<m;i++){
        cin >> a[i];
        a[i]--;
        mp[a[i]]=i;
    }
    vector<vector<int>> v(n,vector<int>(k));
    for(int i=0;i<n;i++){
        for(int j=0;j<k;j++){
            cin >> v[i][j];
            v[i][j]--;
        }
    }
    vector<vector<int>> g(1<<m);
    { // グラフの構築
        for(int i=1;i<(1<<m);i++){
            for(int j=0;j<k;j++){
                int t=0;
                for(int s=0;s<m;s++){
                    if((1<<s)&i){
                        if(mp[v[a[s]][j]]>=0){
                            t|=(1<<mp[v[a[s]][j]]);
                        }
                    }
                }
                g[i].push_back(t);
            }
        }
    }
    vector<int> d(1<<m,1e9);
    d[(1<<m)-1]=0;
    queue<int> q;
    q.push((1<<m)-1);
    while(q.size()){
        int s=q.front(); q.pop();
        for(int t:g[s]){
            if(d[t]>d[s]+1){
                d[t]=d[s]+1;
                q.push(t);
            }
        }
    }
    cout << d[0] << endl;
}

