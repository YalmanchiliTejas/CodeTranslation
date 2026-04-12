/**** [ AkJn ] ****/
#include <bits/stdc++.h>
using namespace std;
 
#define fastIO ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ld long double
#define ll long long
#define input(a,n) for(ll i=0;i<n;i++)cin>>a[i]
#define output(a,n) for(ll i=0;i<n;i++)cout<<a[i]<<" "
#define min3(a, b, c) min(a,min(b, c))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max3(a, b, c) max(a,max(b, c))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))
#define yay(x) cout<<endl<<"yay"<<x<<endl;
// #define debug(a) do { std::cout << "Value of " << #a << " is: " << (a) << '\n'; } while(false);
// #define dbg(a) do { std::cout << "Value of " << #a << " is: " << (a) << '\n'; } while(false);
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define dbgendl(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); cout<<endl;}
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}

#define fori(x) for(ll int i = 0; i < x; ++i)
#define forj(x) for(ll int j = 0; j < x; ++j)
#define fork(x) for(ll int k = 0; k < x; ++k)
#define forl(x) for(ll int l = 0; l < x; ++l)
#define fr(i,a,n) for(ll int i=a; i<n; i++)

/* CHECK THESE POINTS BEFORE SUBMITTING
 * Read the question carefully.
 * Read the code once before final submission.
 * Check the extremities of the constraints.
 * Always check if Binary Search can be applied.
 * 0 is better than -1.
*/

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
 
    /* 
     * THINK MATHEMATICALLY. IT IS NOT AS TOUGH AS IT SEEMS.
    */
 
    fastIO
    ll n;
    cin>>n;
    ll a[n];
    for (ll int i = 0; i < n; ++i)
    {
        cin>>a[i];
    }

    std::vector<vector<ll> > dp(n,vector<ll>(n));

    for (ll int l=n; l >=0; --l)
    {
        for (ll int r = 0; r < n; ++r)
        {
            if(l==r){
                dp[l][r] = a[l];
            }
            else if(l>r){
                continue;
            }
            else{
                dp[l][r] = max(a[l]-dp[l+1][r],a[r]-dp[l][r-1]);
            }
        }
    }

    ll ans = dp[0][n-1];
    cout << ans << endl;
    return 0;
}
 
 
// ll int binsearch(ll int l, ll int r){
//     while(l<r){
//         ll int mid = l+(r-l)/2;
//         if(check(mid)){
//             r = mid;
//         }
//         else{
//             l = mid + 1;
//         }
//     }
//     return r;
// }
 
// int find_set(int a){
//     if(a==parent[a]){
//         return a;
//     }
//     return parent[a] = find_set(parent[a]);
// }
 
// void union_sets(int a, int b){
//     a = find_set(a);
//     b = find_set(b);
//     if(a!=b){
//         parent[b] = a;
//         size[a] += size[b];
//     }
// }
 
// bool isPrime(ll int n) 
// {
//     if (n <= 1) return false; 
//     if (n <= 3) return true; 
 
//     if (n%2 == 0 || n%3 == 0) return false; 
  
//     for (ll int i=5; i*i<=n; i=i+6) 
//         if (n%i == 0 || n%(i+2) == 0) 
//            return false;
 
//     return true; 
// }
 
// Driver function to sort the vector elements 
// by second element of pairs 
// bool sortbysec(const pair<int,int> &a, 
//               const pair<int,int> &b) 
// { 
//     return (a.second < b.second); 
// }
 
 
// Driver function to sort the vector elements by  
// first element of pair in descending order 
// bool sortinrev(const pair<int,int> &a,  
//                const pair<int,int> &b) 
// { 
//        return (a.first > b.first); 
// }
 
// ll int gcd(ll int a, ll int b)  
//  {  
//     // Everything divides 0  
//     if (a == 0 || b == 0)  
//         return 0;  
   
//     // Base case     
//     if (a == b)  
//         return a;  
   
//     // a is greater  
//     if (a > b)  
//         return gcd(a-b, b);  
//     return gcd(a, b-a);  
//  }