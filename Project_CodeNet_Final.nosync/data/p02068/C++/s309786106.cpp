#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

typedef long long ll;

int N;
ll A[2000];
set<ll> sosu;

ll gcd(ll a, ll b){
    if(b == 0)return b;
    else return gcd(b, a % b);
}

void bunkai(ll a){
    for(ll waru = 2; waru * waru <= a; waru++){
        while(a % waru == 0)a /= waru, sosu.insert(waru);
    }
    if(a != 1)sosu.insert(a);
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> A[i];
        bunkai(A[i]);
    }
    ll ans = 0;
    for(auto it = sosu.begin(); it != sosu.end(); it++){
        ll sum = 0;
        ll waru = (*it);
        for(int i = 0; i < N; i++){
            if(A[i] == 1)continue;
            if(A[i] % waru == 0)sum += A[i];
        }
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}


