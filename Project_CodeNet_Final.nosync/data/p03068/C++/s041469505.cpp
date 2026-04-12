#include<bits/stdc++.h>
#include<iomanip>

using namespace std;
using ll =long long;
constexpr int mod = 1e9+7;
constexpr int md = mod;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string str;
    int k;
    cin>>n>>str>>k;
    char c = str[k-1];
    string ans = str;
    for(int i=0;i<n;++i){
        if(c != ans[i]) ans[i] = '*';
    }
    cout << ans << endl;
    return 0;
}

