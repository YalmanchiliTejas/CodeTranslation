#include <bits/stdc++.h>
using namespace std;
int n;
long long p1,p2;
vector<pair<int,int> > v;
long long mx,mn=0x3f3f3f3f3f3f3f3f,x[200001],y[200001];
long long ans=0x3f3f3f3f3f3f3f3f;
int main() {
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>p1>>p2;
        mx=max(mx,p1); mn=min(mn,p1);
        mx=max(mx,p2); mn=min(mn,p2);
        if (p1>p2) swap(p1,p2);
        v.push_back({p1,p2});
    }
    sort(v.begin(),v.end());
    for (int i=0; i<n; i++) {x[i]=v[i].first; y[i]=v[i].second;}
    long long mnr=x[0],mxr=x[n-1],mnb=0x3f3f3f3f3f3f3f3f,mxb=0;
    for (int i=0; i<n; i++) {
        mnb=min(mnb,y[i]); mxb=max(mxb,y[i]);
    }
    ans=min(ans,(mxr-mnr)*(mxb-mnb));
    multiset<long long> s;
    for (int i=0; i<n; i++) s.insert(x[i]);
    ans=min(ans,(mx-mn)*((*prev(s.end()))-(*s.begin())));
    for (int i=0; i<n; i++) {
        s.erase(s.find(x[i]));
        s.insert(y[i]);
        ans=min(ans,(mx-mn)*((*prev(s.end()))-(*s.begin())));
    }
    cout<<ans<<'\n';
}
/*
7
1 5
1 6
2 3
3 9
5 6
7 7
7 8
*/