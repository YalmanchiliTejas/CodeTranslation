#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int main(){
    int n;
    cin >> n;
    long long int x;
    long long int answer = 0LL;
    long long int sum = 0LL;
    for(int i = 0; i < n; i++){
        cin >> x;
        answer += sum*x;
        sum += x;
        sum %= MOD;
        answer %= MOD;
    }
    cout << answer << "\n";
    return 0;
}