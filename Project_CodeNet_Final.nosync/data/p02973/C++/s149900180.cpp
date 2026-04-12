#include <bits/stdc++.h>
using namespace std;

int getLISLength(vector<int>& num) {
    int length = num.size();
    vector<pair<int,int>> ivec;
    for (int i = 0; i < length; ++i) {
        if (ivec.size() == 0 || ivec.back() < make_pair(num[i],i))
            ivec.push_back({num[i],i});
        else {
            int pos = lower_bound(ivec.begin(),ivec.end(),make_pair(num[i],i)) - ivec.begin();
            ivec[pos] = {num[i],i};
        }
    }
    return ivec.size();
}
int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    reverse(a.begin(),a.end());
    cout<<getLISLength(a);
    return 0;
}