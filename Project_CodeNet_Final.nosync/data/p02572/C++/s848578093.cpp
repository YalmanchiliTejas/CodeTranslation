#include <string>
#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
int main()
{
    const long long modNum = 1e9 + 7;
    int n;
    cin >> n;
    vector<long long> data(n);
    rep(i,n){
        long long tmp;
        cin >> tmp;
        data[i] = tmp % modNum;
    }
    /*
    rep(i,n){
        cout << data[i] << endl;
    }
    */
    long long rightSum = 0, tot = 0;
    rightSum = data[n-1];
    for(int i = n-2; i >= 0; i--){
        tot = (tot + data[i] * rightSum % modNum) % modNum;
        rightSum = (rightSum + data[i]) % modNum;
    }
    cout << tot << endl;
}