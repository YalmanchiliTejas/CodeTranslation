#include <bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x <<  " " << x << endl;
#define all(x) x.begin(), x.end()
typedef std::vector<string> vs;
typedef std::vector<bool> vb;
typedef std::pair<int, int> pii;
typedef long long ll;
typedef std::vector<ll> vl;
typedef std::vector<vector<ll>> vvl;
const int inf = 1e9 + 5;

template <typename T>
void print(T v){ for(auto i= v.begin(); i!=v.end(); i++)cout<<setw(2)<<*i<<" ";cout<<endl; }
template <typename T>
void print_vv(T v, bool same_line=true){
for(auto i= 0; i<v.size(); i++){cout<<"{";for(auto j = 0; j!=v[i].size(); j++){cout<<setw(3)<<v[i][j]<<",";}cout<<"},";if(same_line) cout<<endl;}cout<<endl;}

int main(){
    int n; 
    while(cin>>n){
        vl a(n);
        for(int i=0; i<n; i++)
            cin>>a[i];
        
        vvl dp(n, vl(n));

        for(int l=0; l<n; l++){
            for(int r=l; r>=0; r--){
               	// cout<<l<<" "<<r<<" "<<endl;
               	if(l==r)
					dp[l][r] = a[l];
				else 
					dp[l][r] = max(a[l] - dp[l-1][r] , a[r] - dp[l][r+1]);
            }
        }
		cout<<dp[n-1][0]<<endl;

        // for(int l=n-1; l>=0; l--){
        //     for(int r=l; r<n; r++){
        //         cout<<l<<" "<<r<<" "<<r-l<<endl;
        //         if(l==r)
        //             dp[l][r] = a[l];
        //         else 
        //             dp[l][r] = max(a[l] - dp[l+1][r], a[r] - dp[l][r-1]);
        //     }
        // }
        // cout<<dp[0][n-1]<<endl;
    }
    return 0;
}