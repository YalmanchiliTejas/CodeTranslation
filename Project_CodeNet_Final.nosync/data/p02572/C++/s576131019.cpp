#include<iostream>
#include<vector>
using namespace std;
// modは一気にやってはいけない。だんだんです。
// なので一個ずつやります。

int main(){
    int n;
    long long int sum = 0;
    int mod = 1000000007;
    cin >> n;
    vector<int>num(n);
    for(int i = 0; i < n; i++){
        cin >> num[i];
        sum += num[i];

        // 足し算する前に各項をmodしとく
        sum %= mod;
    }

    long ans = 0;

    for(int i = 0; i < n; i++){
        sum -= num[i]; //減らしていく
        if(sum < 0) sum += mod;
        ans += num[i]*sum;
        ans %= mod;
    }

    cout << ans << endl;
}