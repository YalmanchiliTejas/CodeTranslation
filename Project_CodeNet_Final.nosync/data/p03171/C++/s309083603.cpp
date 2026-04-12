#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define endl '\n'
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set =
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ll memo[3001][3001],arr[3001];
int a;
ll solve(int s,int e){
    if(s>e)
        return 0;
    ll &cur=memo[s][e];
    if(cur!=-1)
        return cur;
    if(s==e)
        return arr[s];
    cur=max(arr[s]-solve(s+1,e),arr[e]-solve(s,e-1));
    return cur;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    memset(memo,-1,sizeof(memo));
    cin>>a;
    for(int i=0;i<a;i++)
        cin>>arr[i];
    cout<<solve(0,a-1);
}