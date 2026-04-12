#include<bits/stdc++.h>
#define llu unsigned long long
#define ll long long
#define INF 0x3f3f3f3f
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define to_lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower);
#define to_upper(s) transform(s.begin(), s.end(), s.begin(), ::toupper);

using namespace std;

// scan vector
template <typename T> 
inline istream &operator>>(istream &in, vector<T> &a) {
    for(auto &x : a) in >> x;
    return in;
}
// print vector
template <typename T> 
inline ostream &operator<<(ostream &out, vector<T> &a) {
    for(auto &x : a) out << x <<" ";
    return out;
}
// scan pair
template <typename T, typename U> 
inline istream &operator>>(istream &in, pair<T,U> &a) {
    in >> a.first >> a.second; 
    return in;
}
int n,k;
vector<ll> a;
vector<vector<ll> > dp;
vector<vector<bool> > visited;
ll solve(int first, int last)
{
    if(first>last)
        return 0;

    if(visited[first][last])
        return dp[first][last];
    
    visited[first][last]=true;

    if(first==last)
        return dp[first][last]=a[first];
    
    dp[first][last]=max(a[first]-solve(first+1,last),a[last]-solve(first,last-1));
    
    return dp[first][last];
}

int main()    
{
    #ifdef SANS
        freopen("ongoingin.txt","r",stdin);
        freopen("ongoingout.txt","w",stdout);
    #endif
    fast
    int t=1;
    // cin>>t;
    while(t--)
    {
        cin>>n;
        dp.resize(n,vector<ll>(n,-1));
        a.resize(n);
        cin>>a;
        visited.resize(n,vector<bool>(n,0));
        cout<<solve(0,n-1);
    }
    #ifdef SANS
        cout<<"\nTime Elapsed:"<<1.0*clock()/CLOCKS_PER_SEC <<"sec\n";
    #endif
}