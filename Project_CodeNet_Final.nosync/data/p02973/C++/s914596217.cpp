#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n, a[100005];
multiset<int> S;
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for(int i = 1; i <= n; ++i){
        auto it = S.lower_bound(a[i]);
        if(it != S.begin()) S.erase(--it);
        S.insert(a[i]);
    }
    cout << S.size() << '\n';
    return 0;
}