#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

int N;
ll a[51];

int main(){
    cin >> N;

    for(int i = 0; i < N; ++i){
        cin >> a[i];
    }

    sort(a, a + N);

    ll ans = 0;
    while(a[N - 1] >= N){
        ll sum = 0;
        vector<ll> x;
        for(int i = 0; i < N; ++i){
            if(a[i] > N - 1)
                x.push_back(a[i] / N);
            else 
                x.push_back(0);
            sum += x[i];
        }
        for(int i = 0; i < N; ++i){
            a[i] -= N * x[i];
            a[i] += (sum - x[i]);
        }

        ans += sum;
        sort(a, a + N);
    }
    cout << ans << endl;
    
    return 0;
}
