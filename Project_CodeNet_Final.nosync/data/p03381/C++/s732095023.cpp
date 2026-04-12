#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef vector<int> vi;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rInt(a) scanf("%d",&a);

main(){
    int n; scanf("%d",&n);
    vi arr (n);
    rep(i,n) scanf("%d",&arr[i]);
    vi arr2 = arr;
    sort(arr2.begin(),arr2.end());
    int l = arr2[(n/2)-1], r = arr2[n/2];
    rep(i,arr.size()){
        if(arr[i]<=l) printf("%d\n",r);
        else printf("%d\n",l);
    }  
}