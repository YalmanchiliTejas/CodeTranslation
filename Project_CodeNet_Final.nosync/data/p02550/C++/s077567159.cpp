#include <bits/stdc++.h>
using namespace std;
using ll = long long;


/*  
    
*/

void test_case(){
    //int n; cin >> n;
    
    ll n, x, m; cin >> n >> x >> m;
    ll res = x;
  
  
    n--;
    
    map< ll, ll > mp;
    
    ll cnt = 0;
    vector < ll > sum;
    while(n--){
        x = (x*x)%m;
        if(mp.count(x)){
            n++;
            int from = mp[x];
            ll curr = 0;
            for(int i = from; i < sum.size(); i++)
                curr+= sum[i];
            
            ll interval = sum.size() - from;
            res += (n/interval)*(curr);
            
            int left = (n % interval);
            for(int i = from; i < from + left; i++)
                res += sum[i];
            cout << res << endl;
            return;
        }
        mp[x] = cnt;
        sum.push_back(x);
        res += x;
        cnt++;
    }
    
    cout << res << endl;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; t = 1;
    //cin >> t;
    while(t--)
        test_case();
    return 0;
}
