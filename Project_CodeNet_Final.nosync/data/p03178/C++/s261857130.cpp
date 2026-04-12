#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define scanVec(vec , n) for(int i = 0; i < n ; i++){ cin>>vec[i];}
#define printVec(vec , n) for(int i = 0; i < n ; i++){ cout<<vec[i]<<" ";}
#define S second
#define F first
const int  MOD = 1e9 + 7;
const int  N = 10005;
ll dp[N][105][2];
string K;
int d , n;

ll rec(int ind, int s, int less){
    if(ind == n) return s == 0;
    ll res = dp[ind][s][less] , k ;
    if(res != -1) return res;
    res = 0;
    for(int i = 0; i <= 9; i++){
        if(less){
            res += rec(ind + 1 , (s + i) % d, 1);
        }else{
            if(i > K[ind]-'0')break;
            if(i == K[ind]-'0') res += rec(ind + 1,(s + i)%d , 0);
            if(i < K[ind]-'0') res += rec(ind + 1,( s + i )%d ,1);
        }
        res %= MOD;
    }
    dp[ind][s][less] = res;
    return res;
}

//  a d f j k  l  ;
int main(){
    ios::sync_with_stdio(0);  cin.tie(0);
    cin>>K>>d;
    n = K.size();
    memset(dp, -1, sizeof(dp));
    cout << (rec(0,0,0) - 1 + MOD)%MOD << endl;

    return 0;
}