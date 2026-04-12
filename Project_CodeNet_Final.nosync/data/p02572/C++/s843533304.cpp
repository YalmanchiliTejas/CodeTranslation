#include<algorithm>
#include<cmath>
#include<iostream>
#include<vector>
#include<string>
using namespace std;
typedef long long ll;

#define REP(i, n) for(ll i=0;i<ll(n); i++)

int main(){
    int N;
    vector<long long int> A;

    int i, j;

    cin >> N;
    for(i=0;i<N;i++){
        ll ai;
        cin >> ai;
        A.push_back(ai);
    }

    ll S = 0;
    ll sum = 0;
    ll mod = 1000000000 + 7;
    for(j=1;j<N;j++){
        sum += A[j];
        sum = sum % mod;
    }

    for(i=0;i<N-1;i++){
        S += A[i] * sum;
        S =  S % mod;
        sum -= A[i+1];
        if(sum < 0){sum += mod;}
    }

    cout << S << endl;

    return 0;
}
