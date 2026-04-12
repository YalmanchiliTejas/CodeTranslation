#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<utility>
#include<map>
#include<set>
#include<string>

using namespace std;
#define ll long long

int main(){
    ll N;
    ll a[5],k,sum = 0;
    ll cnt = 1;
    bool f;
    cin >> N;
    vector<ll> H(N);
    for(int i = 0; i < N; i++){
        cin >> H[i];
    }
    for(int i = 1; i < N; i++){ 
        f= true;
        for(int j = 0; j < i; j++){
            if(H[j] > H[i])f = false;
        } 
        if(f)cnt++;
    }
    cout << cnt << endl;   
}
