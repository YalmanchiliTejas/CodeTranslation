#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i,n,k) for(int i=(n);i<(k);i++)
#define ALL(a)  (a).begin(),(a).end()
ll ans=0;
void Main(){
    ll n, x, m;
    cin >> n >> x >> m;
    ll x2 = x;
    if(x == 0) ans = 0;
    else if(x == 1) ans = n;
    else{
        vector<int> to(m+1, -1);
        while(to[x] < 0){
            to[x] = x * x % m;
            x = x * x % m;
        }
        ll looplen = 0, loopsum = 0;
        ll init = x;
        do{
            looplen++;
            loopsum += x;
            x = to[x];
        }while(x != init);
        //cout << loopsum << " " << looplen << " " << loopsum * (n / looplen) << endl;
        while(x2 != x){
            ans += x2;
            x2 = x2 * x2 % m;
            n--;
            if(n == 0) break;
        }
        ans += loopsum * (n / looplen);
        n %= looplen;
        while(n){
            ans += x2;
            x2 = x2 * x2 % m;
            n--;            
        }
    }  
    cout << ans << endl;
}
int main(){
    Main();
    /*
    東方風神録は神が出てくるので当然神ゲー
    */
    return 0;
}