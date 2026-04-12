#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<map>
#include<queue>
#include<set>
#include<bitset>
#include<stdio.h>
#include<deque>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main()
{
    int n, ans = 1;
    cin >> n;
    vector<int> h(n);
    rep(i, n)cin >> h[i];
    for(int i = 1; i < n; i++){
        bool flag = true;
        for(int j = 0; j < i; j++){
            if(h[j] > h[i]) flag = false;
        }
        if(flag)ans++;
    }
    cout << ans << endl;
}