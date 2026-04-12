#include<bits/stdc++.h>
#include<iomanip>

using namespace std;
using ll = unsigned long long;
constexpr int mod = 1e9+7;
constexpr int md = mod;
int main(){
    int ret = 1;
    int n;
    cin>>n;
    vector<int> v(n);
    for(auto & a : v) cin>>a;
    for(int i=1;i<n;++i){
        bool ok = true;
        for(int j=0;j<i;++j){
           if(v[j] > v[i]) ok = false; 
        }
        if(ok)ret++;
    }
    cout << ret <<endl;
    return 0;
}

