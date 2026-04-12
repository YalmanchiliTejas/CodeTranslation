#include <iostream>
using namespace std;

const int mod = 1000000007;

int main(){
    int n;
    cin >> n;
    int list[n];
    long long int sum = 0;
    for (int i = 0; i < n; ++i){
        cin >> list[i];
        sum += list[i];
        sum %= mod;
    }
    long long int result = 0;
    for (int i = 0; i < n; ++i){
        sum -= list[i];
        if (sum < 0) sum += mod;
        result += (sum * list[i]);
        result %= mod;
    }
    cout << result << "\n";
}
