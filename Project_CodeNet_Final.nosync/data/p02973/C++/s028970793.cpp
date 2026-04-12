#include<bits/stdc++.h>

#define hell                         1000000007
#define lcm(a,b)                     (a*b)/__gcd(a,b)
#define ll                           long long
#define vll                          vector<ll>
#define vi                           vector<int>
#define pll                          vector< pair<ll,ll> >
#define pb                           push_back
#define mp                           make_pair
#define all(v)                       v.begin(),v.end()
#define lbnd                         lower_bound
#define ubnd                         upper_bound
#define bs                           binary_search
#define F                            first
#define S                            second
#define rep(i,a,b)                   for(i=a;i<b;i++)
#define parr(a,n)                    for(ll it=0;it<n;it++) cout<<a[it]<<" ";cout<<endl;
#define pcont(a)                     for(auto it:a) cout<<it<<" ";cout<<endl;
#define ret(x)                       return cout<<x,0;
#define endl                           '\n'

/*constants*/
#define MAXN                         100005
#define PI                           3.14159265358979323846

/*debug*/
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>void __f(const char* name, Arg1&& arg1){ std::cout << name << " : " << arg1 << '\n';}
    template <typename Arg1, typename... Args>void __f(const char* names, Arg1&& arg1, Args&&... args){const char* comma = strchr(names + 1, ','); std::cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);}
#else
#define trace(...)
#endif

using namespace std;
int MinimumNumIncreasingSubsequences(int arr[], int n) 
{ 
    multiset<int> last; 
  
    // last element in each  increasing subsequence  
    // found so far 
    for (int i = 0; i < n; i++) { 
  
        // here our current element is arr[i] 
        multiset<int>::iterator it = last.lower_bound(arr[i]); 
  
        // iterator to the first element larger  
        // than or equal to arr[i] 
        if (it == last.begin()) 
  
            // if all the elements in last larger 
            // than or to arr[i] then insert it into last 
            last.insert(arr[i]); 
  
        else { 
            it--; 
  
            // the largest element smaller than arr[i] is the number 
            // before *it which is it-- 
            last.erase(it); // erase the largest element smaller than arr[i] 
            last.insert(arr[i]); // and replace it with arr[i] 
        } 
    } 
    return last.size(); // our answer is the size of last 
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    
    ll i,j,n,m,k,cnt=0,ans=0,t=1;
    cin>>n;
    int a[n];
    rep(i,0,n) cin>>a[i];
    // cout<<(LongestIncreasingSubsequenceLength(a))<<endl;
    ret(MinimumNumIncreasingSubsequences(a,n))
    
    return 0;
}