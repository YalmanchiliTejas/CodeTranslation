#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <assert.h>
#include <queue>
#include <string.h>
#include <string>
#include <set>
#include <memory.h>
#include <functional>
#include <bitset>
using namespace std;
#define ll long long

const int N = 2e5+15;
pair<int,int> in[N];

ll minMaxR(pair<int,int> maxIn,int n) {
    priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    ll ret = 4e18;
    const int inf = 2e9;
    pq.push(make_pair(maxIn.first,inf));
    pq.push(make_pair(in[0].second,inf));
    int R = max(in[0].second,maxIn.first);
    int len = maxIn.second - in[0].first;
    for(int i=1;i<n;++i) {
        pq.push(in[i]);
        R = max(R,in[i].first);
    }
    while(true) {
        pair<int,int> v = pq.top();
        if(v.first==inf) {
            break;
        }
        pq.pop();
        ret = min(ret, (ll)(R- v.first)*len);
        R = max(R,v.second);
        pq.push(make_pair(v.second,inf));
    }
    return ret;
}

void solve() {
    int n;
    scanf("%d",&n);
    if(n==1) {
        cout<<0<<endl;
        return;
    }
    int ind = 0,maxi = 0;
    for(int i=0;i<n;++i) {
        scanf("%d %d",&in[i].first,&in[i].second);
        if(in[i].first>in[i].second) {
            swap(in[i].first,in[i].second);
        }
        if(maxi<in[i].second) {
            ind = i;
            maxi = in[i].second;
        }
    }
    pair<int,int> maxIn = in[ind];
    for(int i=ind;i<n-1;++i) {
        in[i] = in[i+1];
    }
    --n;
    sort(in,in+n);
    ll ret = minMaxR(maxIn, n);
    //when min B max R
    int Bmini  = min(in[0].first,maxIn.first), Bmaxi = max(in[0].first,maxIn.first);
    int Rmaxi = maxIn.second,Rmini = in[0].second;
    for(int i=1;i<n;++i) {
        Bmaxi = max(Bmaxi,in[i].first);
        Rmini = min(Rmini,in[i].second);
    }
    ret = min(ret, (ll)(Bmaxi - Bmini)*(Rmaxi - Rmini));
    printf("%lld\n",ret);
}

int main() {
    //freopen("/Users/gotop/Documents/ps_practice/ps_practice/input.txt", "r", stdin);
    solve();
}
