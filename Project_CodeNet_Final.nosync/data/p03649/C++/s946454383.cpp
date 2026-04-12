#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll n;
    cin >> n;
    priority_queue<ll> que;
    for(int i=0;i<n;i++){
        ll a;
        cin >> a;
        que.push(a);
    }
    ll cnt = 0;
    while(que.top()+cnt >= n){
        ll a = que.top()+cnt;
        que.pop();
        ll x = (a-n)/n + 1;
        a -= (n+1)*x+cnt;
        que.push(a);
        cnt += x;
    }
    cout << cnt << endl;
    return 0;
}