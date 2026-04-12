#include <bits/stdc++.h>
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
using namespace std;



int main(){
    int N;
    cin >> N;
    int64 things[N], prefixSum[N];
    int64 total = 0;
    for (size_t i = 0; i < N; i++)
    {   
        prefixSum[i] = (total % 1000000007);
        cin >> things[i];
        things[i] %= 1000000007;
        total += (things[i] % 1000000007);
    }
    total = 0;
    for(int i = N-1; i > 0; i--){
        int64 tmpt = (things[i] * (prefixSum[i]%1000000007));
        total += tmpt%1000000007;
    }
    cout << total%1000000007;
}