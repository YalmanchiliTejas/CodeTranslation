#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
//using namespace __gnu_pbds;

#define ll long long int
#define endl "\n"
#define db(x) cout<<#x<<" ->"<<x<<endl
#define db2(x,y) cout<<#x<<"->"<<x<<", "<<#y<<" -> "<<y<<endl
#define db3(x,y,z) cout<<#x<<" -> "<<x<<" , "<<#y<<" -> "<<y<<" , "<<#z<<" -> "<<z<<endl
#define db4(w,x,y,z) cout<<#w <<" -> " << w << " , " << #x<<" -> "<<x<<" , "<<#y<<" -> "<<y<<" , "<<#z<<" -> "<<z<<endl
#define prt(x) for(auto it = x.begin(); it!=x.end(); it++) { cout<<*it<<" "; } cout<< endl
#define IN freopen("input.txt","r",stdin)
//typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int N = (int)2e5+4;

ll dp[N][5];
int n , ara[N];
const ll inf = (ll)1e18;

ll solve(int at , int fl){
    if( at >= n){
        if( n % 2 && fl > 1){ return -inf ; }
        return 0;
    }
    ll &ret = dp[at][fl];
    if(ret!=-1){ return ret ;}
    ret = -inf;
    ret = max(ret,ara[at] + solve(at+2,fl));
    if(fl > 0){
        ret = max(ret,solve(at+1,fl-1));
    }
    return ret;
}

int32_t main(){
    ios_base::sync_with_stdio(false); cin.tie(0);
//    IN;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> ara[i];
    }
    int lagbe = n / 2;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < 3; j++){ dp[i][j] = -1 ; }
    }
    cout << solve(0, 1 + (n%2) ) << endl;;

    return 0;
}
