#include <bits/stdc++.h>

using namespace std;
#define int long long
const int N = 3e3 + 4;
int n;
int arr[N];
int mem[N][N];

int solve(int l , int r ){
    if(l>r){
        return 0;
    }

    if(~mem[l][r])
        return mem[l][r];
    int ret ;
    if(((l+r) % 2) != (n % 2)){
         ret = max(  arr[l] + solve(l+1 , r ) , arr[r] + solve(l , r-1) );
    }
    else{
        ret = min( solve(l+1 , r ) - arr[l] , solve(l , r-1) - arr[r] );
    }
    return mem[l][r] = ret;
}
 main()
{  
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(mem , -1  , sizeof mem);
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
    }
    cout << solve(1 , n) ;

}
