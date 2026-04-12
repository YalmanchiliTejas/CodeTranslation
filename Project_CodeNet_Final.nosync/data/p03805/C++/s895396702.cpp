#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <map>
#include <bitset>
#include <cstdio>
#include <set>
#include <stack>
#include <queue>
#include <cassert>
//#include <bits/stdc++.h>
#define rep(i,n) Rep(i,0,n)
#define Rep(i,k,n) for(int i=k ; i<n ; i++)
#define rep1(i,n) for(int i=1 ; i<=n ; i++)
#define vi vector<int>
#define vii vector<vector<int>>
#define mii map<int,int>
#define Sort(v) sort(v.begin(),v.end())
#define Reverse(v) reverse(v.begin(),v.end())
#define ALL(a)  (a).begin(),(a).end()

typedef long long ll;

//const int MOD = 1000000007;
//const int INF = 1<<30;
using namespace std;

string yn(bool x){
    return x ? "Yes" : "No";
}

bool edge[8][8];
bool visited[8];
int cnt = 0;
int n,m;


void init(){
    rep(i,n) visited[i] = 0;
    visited[0] = true;
}

bool check(){
    bool ans = 1;
    rep(i,n){
        if(!visited[i]) ans = 0;
    }
    
    return ans;
}

void dfs(int x){
    
    if(check()) {
        cnt++;
        return;
    }
    
    rep(i,n){
        if(edge[x][i] and !visited[i]){
            visited[i] = 1;
            dfs(i);
            visited[i] = false;
        }
    }
    
    
    return;
}



int main(){
    cin >> n >> m;
    
    rep(i,m){
        int x,y;
        cin >> x >> y;
        
        edge[x-1][y-1] = edge[y-1][x-1] = 1;
    }
    
    init();
    dfs(0);
    
    cout << cnt << endl;
}




