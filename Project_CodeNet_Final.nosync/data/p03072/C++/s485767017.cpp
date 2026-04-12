#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;
    vector<ll> H(N);
    for(int i=0;i<N;i++){
        cin >> H[i];
    }
    ll ma=H[0];
    ll ct=0;
    for(int i=0;i<N;i++){
        if(H[i]>=ma){
            ma=H[i];
            ct++;
        }
    }
    cout << ct << endl;
}