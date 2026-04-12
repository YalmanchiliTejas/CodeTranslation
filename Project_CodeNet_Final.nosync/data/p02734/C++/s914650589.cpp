#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long int lli;
const lli mod = 998244353;
 
lli solve(int b, int e, lli s, vector<lli> &a){
    if(e-b == 1){
        if(a[b] == s) return 1;
        else return 0;
    }

    lli res = 0;
    int mid = (b+e)/2;
    vector<lli> dpb(s+1, 0), dpb_sum(s+1, 0);
    dpb[0] = 1;
    for(int i=mid-1; i>=b; i--){
        for(int j=s; j>=0; j--){
            if(j+a[i] <= s){
                dpb[j+a[i]] += dpb[j];
                dpb[j+a[i]] %= mod;
            }
        }
        for(int j=0; j<=s; j++){
            dpb_sum[j] += dpb[j];
            dpb_sum[j] %= mod;
        }
    }
    for(int j=0; j<=s; j++){
        dpb_sum[j] %= mod;
    }
    vector<lli> dpe(s+1, 0);
    dpe[0] = 1;
    for(int i=mid; i<e; i++){
        for(int j=s; j>=0; j--){
            if(j+a[i] <= s){
                dpe[j+a[i]] += dpe[j];
                dpe[j+a[i]] %= mod;
            }
        }
        for(int j=0; j<=s; j++){
            dpe[j] %= mod;
        }
        for(int j=0; j<=s; j++){
            res += dpb_sum[s-j]*dpe[j] %mod;
            res %= mod;
        }
    }
    //cout << b << " " << e << " " << mid << " " << res << endl;
    res += solve(b, mid, s, a) +solve(mid, e, s, a);
    res %= mod;
    return res;
}

int main(){
    lli n,s;
    cin >> n >> s;
    vector<lli> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cout << solve(0, n, s, a) << endl;
    return 0;
}