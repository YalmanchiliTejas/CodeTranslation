#include <bits/stdc++.h>
#define MAX 10000007
#define PI acos(-1)
#define eps 1e-8
#define eq(x,y) (fabs((x)-(y)) < eps)
#define debug(x) cout<<x<<endl;
#define endl "\n"
#define MEM(a,x) memset(a,x,sizeof(a))

using namespace std;
typedef long long ll ;
const int INF= 1e9+7;

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ordered_set tree<long long,null_type,less<long long>, rb_tree_tag,tree_order_statistics_node_update>
using namespace __gnu_pbds;
*/
/*
bool sortbysec(const pair<int,int>&a, const pair<int,int>&b)
{
    return (a.second<b.second);
}
*/
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    //cout.tie(NULL);
    int n;
    cin>>n;

    if(n==7 || n== 5 || n==3)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;

    return 0;
}
