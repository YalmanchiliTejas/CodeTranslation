/*
*@Author  Chand Vachhani
*/

#include<bits/stdc++.h>
#define int         long long
#define double      long double
#define vi          vector<int>
#define vii         vector<vector<int>>
#define pii         pair<int,int>
#define mii         map<int,int>
#define pb          push_back
#define pf          push_front
#define mp(a,b)          make_pair((a),(b))
#define vpii        vector<pair<int,int>>
#define fo(i,l,n)   for(int i{l}; i<n; i++)
#define rf(s)       for(auto &c : s)
#define all(a)      (a).begin(),(a).end()
#define rall(a)     (a).rbegin(),(a).rend()
#define PI          3.141592653589
#define sz(x)       (int)x.size()
#define bs(v,n)     binary_search(all((v)),(n))
#define lb(v,n)     lower_bound(all((v)),(n))
#define ub(v,n)     upper_bound(all((v)),(n))
#define tezz        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MOD         1000000007  

using namespace std;

int dp[3005][3005];

signed main(){
    tezz
   
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    for(int L=n-1; L>=0; L--){
        for(int R=L; R<n; R++){
            if(L==R)dp[L][R]=a[L];
            else dp[L][R]=max(a[L]-dp[L+1][R] , a[R]-dp[L][R-1]);
        }
    }
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<n; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[0][n-1] ;
    return 0;
}
