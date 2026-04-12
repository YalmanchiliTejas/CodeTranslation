#include <cstdio>
#include <algorithm>
#include <set>

#define INF 1000000000

#define MAXN 200000

std::multiset <int> sx, sy;
std::multiset <int> ::iterator it;
int ind[MAXN+1];
int x[MAXN+1], y[MAXN+1];

bool cmp(const int &a, const int &b){
    return y[a]-x[a]>y[b]-x[b];
}

bool cmp2(const int &a, const int &b){
    return y[a]>y[b];
}

inline long long cost(){
    int a=0, b=0, c=INF, d=INF;
    a=*(sx.begin());
    b=*(sy.begin());
    it=sx.end();
    it--;
    c=*it;
    it=sy.end();
    it--;
    d=*it;
    return 1LL*(c-a)*(d-b);
}

int main(){
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        scanf("%d%d", &x[i], &y[i]);
        ind[i]=i;
        if(x[i]>y[i]) std::swap(x[i], y[i]);
        sx.insert(x[i]);
        sy.insert(y[i]);
    }

    std::sort(ind, ind+n, cmp);

    long long ans=cost();
    for(int i=0; i<n; i++){
        sx.erase(sx.lower_bound(x[ind[i]]));
        sy.erase(sy.lower_bound(y[ind[i]]));
        std::swap(x[ind[i]], y[ind[i]]);
        sx.insert(x[ind[i]]);
        sy.insert(y[ind[i]]);
        ans=std::min(ans, cost());
    }

    for(int i=n-1; i>=0; i--){
        sx.erase(sx.lower_bound(x[ind[i]]));
        sy.erase(sy.lower_bound(y[ind[i]]));
        std::swap(x[ind[i]], y[ind[i]]);
        sx.insert(x[ind[i]]);
        sy.insert(y[ind[i]]);
        ans=std::min(ans, cost());
    }

    for(int i=0; i<n; i++)
        ind[i]=i;

    std::sort(ind, ind+n, cmp2);

    for(int i=0; i<n; i++){
        sx.erase(sx.lower_bound(x[ind[i]]));
        sy.erase(sy.lower_bound(y[ind[i]]));
        std::swap(x[ind[i]], y[ind[i]]);
        sx.insert(x[ind[i]]);
        sy.insert(y[ind[i]]);
        ans=std::min(ans, cost());
    }

    for(int i=n-1; i>=0; i--){
        sx.erase(sx.lower_bound(x[ind[i]]));
        sy.erase(sy.lower_bound(y[ind[i]]));
        std::swap(x[ind[i]], y[ind[i]]);
        sx.insert(x[ind[i]]);
        sy.insert(y[ind[i]]);
        ans=std::min(ans, cost());
    }

    printf("%lld\n", ans);

    return 0;
}
