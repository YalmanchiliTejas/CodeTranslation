#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;

const int MAX = 200000;
const long long MOD = 1000000007;

int main(){
    int N;
    int A[MAX];
    long long sum = 0;

    cin >> N;
    for(int i = 0;i < N;i++){
        cin >> A[i];
        sum += A[i];
    }

    long long ans = 0;

    for(int i = 0;i < N;i++){
        sum -= A[i];
        ans = (ans + A[i] * (sum % MOD)) % MOD;
    }

    cout << ans << endl;

    return 0;
}
