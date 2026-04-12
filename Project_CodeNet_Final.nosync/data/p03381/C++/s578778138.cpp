#include <bits/stdc++.h>
#define mp make_pair
#define fi first
#define sd second
#define ll long long
#define pli pair<ll,int>

using namespace std;

const int maxn = 500010;
const int maxk = 5010;
const ll oo = 1e9+7;

int m,n,a[maxn],s[maxn],num[maxn],id[maxn];

int cmp (int x,int y) {
    return a[x] < a[y];
}

int main() {
    //freopen("in.txt","r",stdin);
    cin>>n;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
        id[i] = i;
    }
    sort(id+1,id+n+1,cmp);
    for (int i=1;i<=n/2;i++) s[id[i]] = a[id[n/2+1]];
    for (int i=n/2+1;i<=n;i++) s[id[i]] = a[id[n/2]];
    for (int i=1;i<=n;i++) cout<<s[i]<<endl;

}
