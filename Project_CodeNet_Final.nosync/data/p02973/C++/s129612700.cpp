#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 2000000000;
int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    deque<ll> c;//その色の最大値
    for(int i = 0;i < n;i++){
        int p = lower_bound(c.begin(),c.end(),a[i])-c.begin();
        if(p == 0){
            c.push_front(a[i]);
        }else c[p-1]=a[i];
    }
    int ans = c.size();
    cout << ans << endl;
}