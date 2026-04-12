#include <cmath>
    // #include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cassert>
#include <deque>
#include <queue>
#include <map>
#include <set>
#define FOR(j,k,n) for (int j = k; j < (int)(n); j++)
#define MAXN 100000000000000000
#define newl printf("\n")
#define test(t)  int t; cin>>t; for(int tes = 0; tes < t; tes++)
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long int lli;
const int MM = 120000;
lli m,n,k,p1,p,p2,p3,f,a[MM],v[MM];
vector<lli> gr[MM];
lli dfs(lli s)
{
    v[s] = 1;
    lli cnt = 1;
    for(lli u : gr[s])
    {
        if(!v[u])
        {
            p = dfs(u);
            if(p==-1)
            {
                return -1;
            }
            cnt += p%2;
        }
    }
    if(cnt == 2)
    {
        return 0;
    }
    else if(cnt == 1)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

int main(){
    fio;
    lli q;
    cin>>n;
    for (int i=1; i<n; i++) {
        cin>>p1>>p2;
        p1--; p2--;
        gr[p2].push_back(p1);
        gr[p1].push_back(p2);
    }
    
    if(dfs(0) != 0)
        cout<<"First";
    else
        cout<<"Second";
    return 0;
}