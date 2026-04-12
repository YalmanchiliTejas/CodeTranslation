#include <cmath>
#include <cstdio>
#include <stack>
#include <queue>
#include <vector>
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main(){
    string s;
    cin>>s;
    string ans="No";
    for(ll i=0;i<s.size()-1;++i){
        if(s[i]=='A'){
            if(s[i+1]=='C'){
                ans="Yes";
                break;
            }
        }
    }
    cout<<ans<<endl;
}