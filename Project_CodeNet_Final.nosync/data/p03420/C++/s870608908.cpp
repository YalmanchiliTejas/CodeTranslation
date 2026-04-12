#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<string>
#include<functional>
using namespace std;
typedef	long long int ll;

int main(){
    ll n, k;
    cin >> n >> k;
    ll q, r;
    ll res = 0;
    for(int i = k+1; i <= n; i++){
        r = n-n/i*i;
        q = n/i;
        res += q*(i-k);
        if(r >= k && k != 0){
            res += r-k+1;
        }
        if(k==0){
            res += r;
        }
    }
    cout << res << endl;
    return 0;
}