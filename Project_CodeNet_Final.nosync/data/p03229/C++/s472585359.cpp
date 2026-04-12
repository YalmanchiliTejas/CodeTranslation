#include<bits/stdc++.h>
using namespace std;

typedef long long lint;
typedef pair<int, int> P;
#define REP(i, x, n) for(lint i = x ; i < n ; i++)
#define rep(i, n) REP(i, 0, n)
#define repr(i, n) for(lint i = n - 1 ; i >= 0 ; i--)
#define SORT(c) sort((c).begin(), (c).end())

const int IINF = 1e9 + 10;
const lint LLINF = (lint)1e18 + 10;
const lint MOD = (lint)1e9 + 7;
const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
const int dx8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dy8[] = {0, -1, -1, -1, 0, 1, 1, 1};

int main(){
    int n;
    cin >> n;
    vector<lint> a(n);
    rep(i, n){
        cin >> a[i];
    }
    SORT(a);
    lint ans = 0, tmp = 0;
    if(n % 4 == 1){
        tmp += abs(a[n-1] - a[0]) + abs(a[n-1] - a[1]);
        for(int i = n - 2, j = 0, k = 2 ; i > n/2 ; i--, j++, k++){
            tmp += abs(a[i] - a[j]) + abs(a[i] - a[k]);
        }
        ans = max(ans, tmp);
        reverse(a.begin(), a.end());
        tmp = 0;
        tmp += abs(a[n-1] - a[0]) + abs(a[n-1] - a[1]);
        for(int i = n - 2, j = 0, k = 2 ; i > n/2 ; i--, j++, k++){
            tmp += abs(a[i] - a[j]) + abs(a[i] - a[k]);
        }
        ans = max(ans, tmp);
    }else if(n % 4 == 3){
        tmp += abs(a[0] - a[n-1]) + abs(a[0] - a[n-2]);
        for(int i = 1, j = n-1, k = n-3 ; i < n/2 ; i++, j--, k--){
            tmp += abs(a[i] - a[j]) + abs(a[i] - a[k]);
        }
        ans = max(ans, tmp);
        reverse(a.begin(), a.end());
        tmp = 0;
        tmp += abs(a[0] - a[n-1]) + abs(a[0] - a[n-2]);
        for(int i = 1, j = n-1, k = n-3 ; i < n/2 ; i++, j--, k--){
            tmp += abs(a[i] - a[j]) + abs(a[i] - a[k]);
        }
        ans = max(ans, tmp);
    }else if(n == 2){
        ans = abs(a[1] - a[0]);
    }else{
        tmp += abs(a[0] - a[n-1]) + abs(a[0] - a[n-2]);
        for(int i = 1, j = n-1, k = n-3 ; i < n/2 - 1 ; i++, j--, k--){
            tmp += abs(a[i] - a[j]) + abs(a[i] - a[k]); 
        }
        tmp += abs(a[n/2-1] - a[n/2+1]);
        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}