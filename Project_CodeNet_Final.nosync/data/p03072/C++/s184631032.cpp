#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<queue>
#include <climits>
const int mod = 1e9 + 7;
const int INF = 1e9;
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    int a[n];

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int ans = 1;
    for(int i = 1; i < n; i++){
        bool can = true;
        for(int j = 0; j < i; j++){
            if(a[i] < a[j]){
                can = false;
            }
        }
        if(can) ans++;
    }
    cout << ans;
}
