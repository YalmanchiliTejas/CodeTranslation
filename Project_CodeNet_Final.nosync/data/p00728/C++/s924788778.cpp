#include <bits/stdc++.h>
using namespace std;
const int MAX_N=101;

int n,ans;
vector<int> s(MAX_N);

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    while(cin >> n,n){
        for (int i=0;i<n;++i) cin >> s[i];
        sort(s.begin(),s.begin()+n);
        ans=0;
        for (int i=1;i<n-1;++i) ans+=s[i];
        cout << ans/(n-2) << '\n';
    }
}
