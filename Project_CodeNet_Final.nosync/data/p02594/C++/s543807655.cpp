#include<bits/stdc++.h>
using namespace std;
#define vite ios_base::sync_with_stdio(false); cin.tie(NULL);
#define tst lli T; cin>>T; while(T--)
#define mod 1000000007
#define MAX 1e9
#define MIN -1e9
#define lli long long int
#define vt vector
#define pb push_back
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    lli n;
    cin >> n;
    if(n>=30)
        cout << "Yes";
    else
        cout << "No";
    cout<< endl;
    // cout<< fixed << 1.0 * clock() / CLOCKS_PER_SEC << setprecision(10);
    return 0;
}