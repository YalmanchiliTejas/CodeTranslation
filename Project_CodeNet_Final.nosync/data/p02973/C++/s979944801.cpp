#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<numeric>
#include<utility>

using namespace std;

typedef long long int ll;
const int INF = 1<<30;
const long long LINF = 1LL<<60;

int main(){
    int n, ans = 0;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<ll> b(100001, -1);
    for(int i = 0; i < n; i++){
        auto p = lower_bound(begin(b), end(b), a[i]);
        if(p == b.end()){
            b.back() = a[i];
        }else{
            *(p - 1) = a[i];
        }
    }
    ans = b.end() - upper_bound(begin(b), end(b), -1);
    cout << ans << endl;
    return 0;
}
