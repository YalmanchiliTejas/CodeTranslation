#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#define popcount __builtin_popcount
using namespace std;
typedef long long int ll;
typedef pair<ll, int> P;

int main()
{
    int n, s, t; cin>>n>>s>>t;
    ll ds[334], dt[334];
    for(int i=1; i<=n; i++){
        cout<<"? "<<i<<" "<<s<<endl;
        cin>>ds[i];
        cout<<"? "<<i<<" "<<t<<endl;
        cin>>dt[i];
    }
    vector<P> v;
    for(int i=1; i<=n; i++){
        if(ds[i]+dt[i]==ds[t]){
            v.push_back({ds[i], i});
        }
    }
    sort(v.begin(), v.end());
    vector<int> ans;
    ans.push_back(s);
    int p=v[1].second;
    ans.push_back(p);
    int k=2;
    while(p!=t){
        int q=v[k].second;
        cout<<"? "<<p<<" "<<q<<endl;
        ll d; cin>>d;
        if(ds[p]+d==ds[q]){
            p=q;
            ans.push_back(q);
        }
        k++; 
    }
    cout<<"!";
    for(auto x:ans) cout<<" "<<x;
    cout<<endl;
    return 0;
}
