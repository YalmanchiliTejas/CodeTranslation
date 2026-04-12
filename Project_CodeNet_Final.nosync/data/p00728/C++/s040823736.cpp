#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define INF 100000000
#define rep(i,s,n) for (int i = (int)(s); i < (int)(n); i++)
ll mod = 1000000007;
ll mod2 = 998244353;

int main(){
    vector<int> ans;
    while (true){
        int n; cin>>n;
        if (n==0) break;
        vector<int> s(n);
        rep(i,0,n) cin>>s[i];
        sort(s.begin(),s.end());
        int sum = 0;
        rep(i,1,n-1){
            sum+=s[i];
        }
        ans.push_back(sum/(n-2));
    }
    for (int k:ans){
        cout<<k<<endl;
    }
}
