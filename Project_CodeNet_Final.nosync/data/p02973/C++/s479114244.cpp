#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#define eps 1e-8
#define eq(x,y) (fabs((x)-(y)) < eps)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int>pii;
const ll mod= 1e9+7;
long double pi = acosl(-1);
const int inf = 1e9;
const int nmax = 1e5+5;
const int MAXLG = log2(nmax)+1;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ost;


vector<int>g[nmax];
int arr[nmax];

int sarch(int lo, int hi, int x){
    if(g[lo].back()<x) return lo;
    if(g[hi].back()>=x) return hi+1;
    while(hi>lo){
        int mid=(hi+lo)/2;
        if(g[mid].back()>=x) lo=mid+1;
        else hi=mid;
    }
    return hi;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin>>n;
    for(int i=1; i<=n; i++) cin>>arr[i];
    g[1].push_back(arr[1]);
    int sz=1;
    for(int i=2; i<=n; i++){
        int x = arr[i];
        int idx = sarch(1,sz,x);
        g[idx].push_back(x);
        sz=max(sz, idx);
    }
    cout<<sz;
}
/*
9
1 5 0 9 2 6 6 7 8
*/
