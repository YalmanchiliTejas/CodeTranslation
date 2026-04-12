//Code by : Abhishek Tiwari
//codechef.com/users/devil_within || hackerearth.com/@devil_within
#include<bits/stdc++.h>
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long int
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define repr(i,a,b) for(int i=(a);i>(b);--i)
#define mp make_pair
#define pb push_back
#define pf push_front
#define pii pair<int,int> 
#define ff first
#define ss second 
#define mod 1000000007
#define inf 1000000000
#define gcd __gcd
#define lcm(a,b) ((a)*(b))/gcd(a,b)
using namespace std;

/*******************************************************************************************/
/*******************************************************************************************/
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { 
    os<<"["; for(int i=0;i<v.size()-1; ++i)os<<v[i]<<", ";os<<v[v.size()-1]<<"]\n"; return os; 
} 
template <typename T> ostream& operator<<(ostream& os, const set<T>& v) { 
    os<<"{"; for(auto it : v) { os<<it; if(it!=*v.rbegin()) os<<", "; } os<<"}\n"; 
    return os; 
}
template <typename T, typename S> ostream& operator<<(ostream& os, const map<T, S>& v) { 
    os<<"{"; for(auto it:v){ os<<"("<<it.first<<" : "<<it.second<<")"; if(it!=*v.rbegin()) os<<", "; } os<<"}\n"; 
    return os; 
}
template <typename T, typename S> ostream& operator<<(ostream& os, const pair<T, S>& v) { 
    os<<"("; os<<v.first<<", "<< v.second<<")"; 
    return os; 
} 
template<typename T> T maxi(T a,T b){return a>b ? a:b;}
template<typename T> T mini(T a,T b){return a<b ? a:b;}
/*******************************************************************************************/
/*******************************************************************************************/
int fpow(int x, int y, int p); 
int solve(int i , int j , vector<int> &a , int sum , vector<vector<int>> &dp)
{
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(i==j)
    {
        dp[i][i] = a[i];
        return dp[i][i];
    }
    
    int v1 = sum - solve( i +1 , j , a , sum - a[i] , dp);
    int v2 = sum - solve( i , j-1 , a , sum - a[j] , dp);
    dp[i][j] = max( v1 , v2);
    return dp[i][j];
}

int32_t main()  
{
#ifndef ONLINE_JUDGE
//freopen("input.txt" , "r" , stdin);freopen("output.txt" , "w" , stdout);freopen("error.txt" , "w" , stderr);
#endif
fio;
int tcases = 1;
//cin>>tcases;
for(int tcase = 1 ; tcase <= tcases ; ++tcase)
{
    int n;
    cin>>n;
    vector<int>a(n);
    rep( i, 0, n) cin>>a[i];
    vector<vector<int>> dp(n);
    rep(i , 0 , n) dp[i].resize(n , -1);
    int sum  = accumulate( a.begin() , a.end() , 0LL);
    int f = solve(0 , n-1 , a , sum , dp);
    int s = sum - f;
    cout<< f - s <<"\n";
    //cout<<"Case #"<<tcase<<": ";
}
return 0;
}



//Functions 

int fpow(int x, int y, int p) { 
    int res = 1; 
   x = x % p;  
   while (y > 0) { 
     if (y & 1) 
        res = (res * x) % p; 
     y = y >> 1; 
        x = (x * x) % p; 
    } 
    return res; 
} 

