#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define gt(n) scanf("%d", &n)
#define gtll(n) scanf("%ld", &n)
#define out(n) printf("%d", n)
#define outll(n) printf("%ld", n)
#define loop(n) for(int i=0; i<n; i++)
#define MAXX 1001
#define mem(x, y) memset(x, y, sizeof(x))
#define loop1(n) for(int i=1; i<=n; i++)
#define ll long long
#define pb push_back
#define pi acos(-1)
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
//(only in c)char[33];itoa(n,buffer,base);printf("%s",buffer);
#define dec_to_bin(n) std::string binary = std::bitset<64>(n).to_string();
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL)
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
int main()
{
    fast;
    int n;
    cin>>n;
    int a[n+7];
    int x=-1,c=0;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i]>=x)
        {
            c++;
            x=a[i];
        }
    }
cout<<c<<endl;
    return 0;
}
