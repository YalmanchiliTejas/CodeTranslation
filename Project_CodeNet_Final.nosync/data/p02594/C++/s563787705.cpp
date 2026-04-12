
//////////////      VATSAL AGARWAL       ////////////////////////
////////////// Codeforces id : warhead38 ////////////////////////
////////////// Codechef   id : vatsal38  //////////////////////// 


#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define endl '\n'
#define loop(var,a,b,c) for(ll var=a;var<=b;var+=c)
#define intarr(arr,n) ll arr[n];for(ll i=0;i<n;i++)cin>>arr[i]
#define inparr(arr,n) for(ll i=0;i<n;i++)cin>>arr[i]
#define inpvec(vec,n) for(ll i=0;i<n;i++){ll var;cin>>var;vec.push_back(var);}
#define pb push_back
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define mod 1000000007
#define newline cout<<endl
#define ump unordered_map<ll,ll>
#define vec vector<ll>
#define mkp make_pair
#define disp(var1,var2) cout<<var1<<" "<<var2<<endl;
#define all(v)             v.begin(),v.end()
#define cout(var) cout<<var<<endl
#define mod2 998244353
#define fbo find_by_order  /// find kth smallest by passing k-1
#define ook order_of_key  //// find no of smaller items less than k
#define teensort(a,r,g,b) a[0]=r;a[1]=g;a[2]=b;sort(a,a+3);
#define ss second
#define ff first
#define displayarray(a,n) for(ll i=0;i<n;i++)cout<<a[i]<<" "; cout<<endl;
#define pi pair<ll,ll>
#define meramax 1e18
#define meramin -1e18
#define percentile 1000000007
#define PI 3.14159265358979323846
#define input2darr(n,m,in) ll a[n+1][m+1];if(in==0){loop(i,0,n-1,1)loop(j,0,m-1,1)cin>>a[i][j];}else{loop(i,1,n,1)loop(j,1,m,1)cin>>a[i][j];}
#define output2darr(n,m,in) if(in==0){loop(i,0,n-1,1){loop(j,0,m-1,1)cout<<a[i][j]<<" ";cout<<endl;}}else{loop(i,1,n,1){loop(j,1,m,1)cout<<a[i][j]<<" ";}cout<<endl;}
#define minheap priority_queue<ll>
#define maxheap priority_queue<ll,vector<ll>,greater<ll>>
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////                                     ///////////////////////////////////////////////////////////////
////////////////////////////////////////              CODE                   ///////////////////////////////////////////////////////////////
////////////////////////////////////////                                     ///////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void AcDegaYe()
{
    int n;
    cin>>n;
    if(n>=30)
    {
        cout("Yes");
        return;
    }
    cout("No");
}
int main()
{   
    fastio

    // #ifndef ONLINE_JUDGE
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // #endif

    //ll t;
    //cin>>t;
    ll t=1;
    while(t--)
    {
        AcDegaYe();
    }
    //cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}