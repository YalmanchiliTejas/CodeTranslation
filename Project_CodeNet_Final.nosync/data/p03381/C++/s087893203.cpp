#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <time.h>
#include <algorithm>
#include <set>
#define MAXN 222222
#define ll long long
using namespace std;

// 01, 32
// 00, 22


int ans[MAXN+2];


int main() {
    int N;
    cin>>N;
    
    vector<pair<int,int> > vals;
    for(int i=0;i<N;i++) {
        int x;
        cin>>x;
        vals.push_back({x,i});
    }
    
    
    
    sort(vals.begin(),vals.end());
    
    for(int i=0;i<vals.size();i++) {
        if (i <= N/2-1)
            ans[vals[i].second] = vals[N/2].first;
        else
            ans[vals[i].second] = vals[N/2-1].first;
    }
    
    
    for(int i=0;i<N;i++)
        printf("%d\n",ans[i]);
    
    
}