#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll =  long long ;
using P = pair<int,int> ;
const int INF = 1e9;
const int MOD = 1000000007;

int main(){
    while(1){
        int n;
        cin >> n;
        if(n==0) break;
        vector<int> s(n);
        rep(i,n) cin >> s[i];
        int mx = 0,mn = INF,sum = 0;
        rep(i,n){
            sum += s[i];
            mn = min(mn,s[i]);
            mx = max(mx,s[i]);
        }
        cout << (sum-mn-mx)/(n-2) << endl;
    }
    return 0;
}
