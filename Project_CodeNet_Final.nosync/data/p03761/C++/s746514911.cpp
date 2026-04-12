#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    vector<int> cnt(128, INT_MAX);
    for(string s; n--; ) {
        cin>>s;
        array<int, 128> t={};
        for(auto& c: s) ++t[c];
        for(int i=0; i<128; ++i) cnt[i]=min(cnt[i], t[i]);
    }
    for(int i=0; i<128; ++i) if (cnt[i]) cout<<string(cnt[i], i);
    cout<<endl;
}