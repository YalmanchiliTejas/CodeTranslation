#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N;
    cin >> N;
    deque<ll> color;
    rep(i, 0, N){
        ll a; cin >> a;
        auto itr = lower_bound(color.begin(), color.end(), a);
        if(color.begin() == itr){
            color.push_front(a);
        }else{
            *(itr-1) = a;
        }
    }
    cout << color.size() << endl;
    return 0;
}