#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void){
    ll n;
    cin >> n;
    vector<ll> v1(n);
    for(ll i=0; i<n; i++){
        cin >> v1.at(i);
    }
    sort(v1.begin(), v1.end());
    vector<ll> v2;
    ll i = 0;
    for(ll i=0; i<n; i++){
        if(v1.size() > 1){
            switch(i%4){
                case 0:
                    v2.insert(v2.begin(), v1.front());
                    v1.erase(v1.begin());
                    break;
                case 1:
                    v2.push_back(v1.back());
                    v1.pop_back();
                    break;
                case 2:
                    v2.push_back(v1.front());
                    v1.erase(v1.begin());
                    break;
                case 3:
                    v2.insert(v2.begin(), v1.back());
                    v1.pop_back();
                    break;
            }
        }else{
            if(abs(v1.at(0) - v2.front()) > abs(v1.at(0) - v2.back())){
                v2.insert(v2.begin(), v1.at(0));
            }else{
                v2.push_back(v1.at(0));
            }
        }
    }

    ll ans = 0;
    for(ll i=1; i<n; i++){
        ans += abs(v2.at(i) - v2.at(i-1));
    }

    cout << ans << endl;

    return 0;
}