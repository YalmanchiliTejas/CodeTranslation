#include <bits/stdc++.h>
using namespace std;
typedef long long lli;
typedef long double lld;
#define mod 1000000007
#define mod2 998244353
#define fori(n) for (int i = 0; i < n; i++)
#define forj(n) for (int j = 0; j < n; j++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define sortvec(a) sort(a.begin(), a.end())
#define watch(x) cerr << "\n" << (#x) << " is " << (x) << endl
#define cerr if(true)cerr
void print(){cout<<endl;}
template<typename T,typename... Args>
void print(T a, Args... args) {cout<<a<<" ";print(args...);}
lli llipowerp(lli x, lli y, lli p=LLONG_MAX)
{
    lli res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1) res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
lli binarySearch(vector<int> arr, int l, int r, int x)
{
    if (r >= l)
    {
        lli mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}
template <typename T>
inline void printvec(vector<T> inp){
    for(auto it:inp) cout<<it<<" ";
    cout << endl;
}
//---------------------------------------------------------------------------------
int n;
vector<lli> a;
const int N=3010;
lli dp[N][N][2];

lli get(int l,int r,int c){
    if(l>r || l<0 || l>=n ||r<0 || r>=n) return 0;
    if(dp[l][r][c]!=-1) return dp[l][r][c];

    if(l==r){
        if(c==0)
            dp[l][r][c]=a[l];
        else dp[l][r][c]=-1*a[l];
        return dp[l][r][c];
    }

    if(c==0){
        dp[l][r][c]=max(get(l+1,r,1)+a[l],get(l,r-1,1)+a[r]);
        return dp[l][r][c];
    }
    else{
        dp[l][r][c] = min(get(l + 1, r, 0)-a[l], get(l, r - 1, 0)-a[r]);
        return dp[l][r][c];
    }
}

int main(){
    cin>>n;
    int x;
    memset(dp,-1,sizeof(dp));
    fori(n){
        cin>>x;
        a.pb(x);

    }
    // fori(n){
    //     forj(n){
    //         cout<<get(i,j,0)<<","<<get(i,j,1)<<"   ";
    //     }
    //     cout<<endl;
    // }
    cout<<get(0,n-1,0)<<endl;
}