#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int M = 1e9 + 7;

ll mod(ll a){
    return (a%M + M)%M;
}

ll mul(ll a, ll b){
    return mod(mod(a)*mod(b));
}

ll add(ll a, ll b){
    return mod(mod(a)+mod(b));
}
void solve(){
    
    //ifstream myfile;
    //myfile.open("sample.txt");

    int n;
    cin  >> n;

    vector<ll> a(n);
    vector<ll> prefSum(n+1);

    for(int i=0; i<n; i++){
        cin >> a[i];
    }

    for(int i=n-1; i>=0; i--){
        
        prefSum[i] = a[i] + prefSum[i+1];
    }

    ll sum = 0;
    for(int i=0; i<n-1; i++)
    {
        sum = add(sum,mul(a[i],prefSum[i+1]));
    }
    cout << sum;

    return;
}

int main(){
    solve();
    return 0;
}