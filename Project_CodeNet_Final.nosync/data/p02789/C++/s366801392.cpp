#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define ff               first
#define ss               second
#define mp               make_pair
#define pb               push_back
#define pii              pair<int,int>
#define vi               vector<int> 
#define mii              map<int,int>
#define setbits(x)       __builtin_popcountll(x)
#define zerobits(x)      __builtin_ctzll(x)
#define mod              1000000007
#define inf              1e18
#define endl             "\n"

void h_code()
{
 #ifndef ONLINE_JUDGE
     freopen("input.txt", "r", stdin);
     freopen("output.txt", "w", stdout);
 #endif
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

void l_code()
{
 #ifndef ONLINE_JUDGE
     cout<<"\nTime Elapsed: " << 1.0*clock() / CLOCKS_PER_SEC << " sec\n";
 #endif
}
const int N=100005;

int main() {
   // h_code();
    int t=1;
    // cin>>t;
    while(t--)
    {
              int n,m;
              cin>>n>>m;
              if(n==m)  
                cout<<"Yes";
              else 
                cout<<"No";
    }

   // l_code();
}