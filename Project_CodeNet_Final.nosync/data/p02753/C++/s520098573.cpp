#include "bits/stdc++.h"
using namespace std;
#define int long long int
#define endl "\n"
const int MOD=1e9+7;
#ifndef HOME
#define cerr if(0)cerr
#endif

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    set<int>ss;
    for(int i=0;i<s.length();i++){
        ss.insert(s[i]);
    }
    if(ss.size() == 1){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }
    
    return 0;
    
}

