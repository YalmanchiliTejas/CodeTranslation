#include <bits/stdc++.h>

#include <math.h>
#include <stdlib.h>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int n; cin >> n;
    
    cout << n * 800 - n/15 * 200 << endl;

    return 0;
}

