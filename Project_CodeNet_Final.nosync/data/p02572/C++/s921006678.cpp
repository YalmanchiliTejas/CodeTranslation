#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<long> a(n);
    for (long &i: a){
        cin >> i;
    }
    
    long long sum = 0;
    long long product = 0;
    int law = 1000000007;
    for (int j = 0; j < n; j++){
        sum = (sum + a.at(j)) % law;
    }
    for (int i = 0; i < n - 1; i++){
        sum = (sum - a.at(i)) % law;
        if (sum < 0) sum += law;
        product += a.at(i) * sum % law;
    }
    cout << product % law << endl;
}
