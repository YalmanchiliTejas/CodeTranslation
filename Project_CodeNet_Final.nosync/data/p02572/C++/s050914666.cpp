#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <math.h>
#include <string>
#include <limits.h>
#include <iomanip>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <set>
#include <bitset>
#include <unordered_map>
#include <string.h>
#define fastIo                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define MOD 1000000007

using namespace std;
int main()
{
    fastIo;
    ll n;
    cin>>n;

    ll arr[n];
    ll sum = 0;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
        sum%=MOD;
    }
    ll ans = 0;

    for(int i=0;i<n;i++)
    {
        sum-=arr[i];
        sum = (sum+MOD)%MOD;

        ans = (ans+(arr[i]*sum)%MOD)%MOD;
    }

    cout<<ans<<endl;
    
    

   
    return 0;
}