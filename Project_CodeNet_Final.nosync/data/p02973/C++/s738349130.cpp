#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep2(i,i0,n) for(int i=i0;i<n;++i)

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto& ai:a) cin >> ai;

    deque<int> b(1,a[0]);
    rep2(i,1,n) {
        auto itr = lower_bound(b.begin(), b.end(), a[i]);
        if(itr == b.begin()) b.push_front(a[i]);
        else *(--itr) = a[i];
    }
    
    cout << b.size() << endl;
    return 0;
}