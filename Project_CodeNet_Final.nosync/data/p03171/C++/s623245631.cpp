#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
#define trace1(x)                cerr<<#x<<": "<<x<<endl
#define trace2(x, y)             cerr<<#x<<": "<<x<<" | "<<#y<<": "<<y<<endl
#define trace3(x, y, z)          cerr<<#x<<":" <<x<<" | "<<#y<<": "<<y<<" | "<<#z<<": "<<z<<endl
#define trace4(a, b, c, d)       cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl
#define trace5(a, b, c, d, e)    cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<endl
#define trace6(a, b, c, d, e, f) cerr<<#a<<": "<<a<<" | "<<#b<<": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<" | "<<#e<< ": "<<e<<" | "<<#f<<": "<<f<<endl
ll dp[2][3001][3001]; 

ll min_self(ll a, ll b){
    return a<b?a:b; 
}
ll max_self(ll a, ll b){
    return a>b?a:b; 
}
ll sol(ll* arr, int st, int en, int pl){
    //trace3(st, en, pl);
    if(st > en){
        return 0; 
    }
    if(dp[pl][st][en] != -1){
        return dp[pl][st][en];
    }
    if(pl == 0){
        dp[0][st][en] = max_self(arr[st] - sol(arr, st+1, en, 1),arr[en] - sol(arr, st, en-1, 1));
        return dp[0][st][en];
    }
    else{
        dp[1][st][en] = max_self(arr[st] - sol(arr, st+1, en, 0), arr[en] - sol(arr, st, en-1, 0));
        return dp[1][st][en]; 
    }
}

int main(){
	FAST_IO;
    int n; 
    cin >> n; 
    ll a[n]; 
    for(int i=0; i < n; i++){
        cin >> a[i]; 
    }
    for(int i=0; i < 2 ; i++){
        for(int j= 0 ; j < 3001; j++){
            for(int k = 0; k < 3001; k++){
                dp[i][j][k] = -1; 
            }
        }
    }
    sol(a, 0, n-1, 0);
    

   /* for(int i=0; i < 2 ; i++){
        for(int j= 0 ; j < n; j++){
            for(int k = 0; k < n; k++){
                cout << dp[i][j][k] <<" ";
            }
            cout << endl;
        }
        cout << endl;
    }*/

    

    cout << dp[0][0][n-1] <<endl; 
    return 0; 
 }