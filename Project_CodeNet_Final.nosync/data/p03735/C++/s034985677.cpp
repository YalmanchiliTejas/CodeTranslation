#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
typedef long long LL;

int n;
pair<int,int> p[N];
multiset<int> X, Y;

LL cal(){
    LL ret = (*X.rbegin() - *X.begin());
    ret = ret * (*Y.rbegin() - *Y.begin());
    return ret;
}

int main(){
    int a, b;
    while(~scanf("%d", &n)){
        X.clear();
        Y.clear();
        for(int i=0; i<n; i++){
            scanf("%d %d", &a, &b);
            if(a > b)   swap(a, b);
            p[i] = make_pair(a, b);
            X.insert(a);
            Y.insert(b);
        }
        sort(p, p+n);

        LL ans = cal();

        for(int i=0; i<n; i++){
            auto it = X.find(p[i].first);
            X.erase(it);
            it = Y.find(p[i].second);
            Y.erase(it);

            X.insert(p[i].second);
            Y.insert(p[i].first);

            ans = min(ans, cal());
        }
        printf("%lld\n", ans);
    }
    return 0;
}
