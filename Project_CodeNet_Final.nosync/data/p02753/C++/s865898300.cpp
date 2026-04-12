#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pb push_back
#define int long long
#pragma GCC optimize("O3,Ofast,no-stack-protector,unroll-loops,fast-math")
const int maxn=2e3+7;
const int mod=1e9+7;
/*Almost copy pasted part :)*/

int32_t main(){
    string s;
    cin>>s;
    int n=s.size();
    bool A=0;
    bool B=0;
    for(int i=0;i<n;i++){
        if(s[i]=='A')A=1;
        else B=1;
    }
    cout<<(A&&B ? "Yes":"No")<<endl;
}