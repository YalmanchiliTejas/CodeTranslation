#include <bits/stdc++.h>
#include <iostream>
using namespace std;

typedef long long ll;
typedef long double ld;
#define REP(i, n) for (int i = 0; i < n; i++)
#define print(v) cout << v << endl

int main()
{
    int n;
    cin >> n;
    int h[100];
    REP(i,n){
        cin >> h[i];
    }
    int tmp = -1;
    int ans = 0;
    REP(i,n){
        if(h[i]>=tmp){
            ans+=1;
            tmp = h[i];
        }
    }
    print(ans);
}