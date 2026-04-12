#include <bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = n - 1; i >= 0; i--)
#define REP(i,k,n) for(int i = k; i < n; i++)

#define vi vector<int>
#define pb push_back
using namespace std;
typedef long long ll;

int main(){
    int n;
    while(cin >> n,n) {
        vi a;
        int tmp;
        rep(i,n){
            cin >> tmp;
            a.pb(tmp);
        }
        sort(a.begin(),a.end());
        ll sum = 0;
        REP(i,1,n - 1){
            sum += a[i];
        }
        cout << sum / (n - 2) << endl;
    }
    return 0;
}

