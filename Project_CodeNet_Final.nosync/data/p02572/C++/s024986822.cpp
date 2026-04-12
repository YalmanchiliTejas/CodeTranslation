#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
#include <stack>
#include<set>
#include<cstring>
#include <stdio.h>
#include <stdlib.h>
#include <cstdio>
#include <string.h>
#include<iterator>
#include <map>
using namespace std;
// bool cmp(long long a, long long b){
//     return a > b;
// }
int  arr[3500];
string str[10];
char str_arr[5][5];
int matr[25][25], saved_matr[5][5], ish_matr[5][5];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);
    long long t, ch, i, curr, p = 1, x, y, weight, j, k = 0, n, m = 1, ch1, ans = 0;
    long long a, b;
    int fl, fl1, fl2, fl3;
    string s, s1;
//    cin >> t;
    long long f, size_f, size_s, weight1, weight2;
    long long sum, k_min, k_max;
//    for (auto test_case = 0; test_case < t; test_case++) {
//    }
    long long d;
    cin >> n;
    long long* arr = new long long[n];
    sum = 0;
    for (i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    ans = 0;
    for (i = 0; i < n; i++){
        sum = sum - arr[i];
        ch = sum;
        ch = ch % ((long long) 1e9 + 7);
        ch = ch * arr[i];
        ch = ch % ((long long) 1e9 + 7);
        ans += ch;
        ans = ans % ((long long) 1e9 + 7);
    }
    cout << ans;
    return 0;
}