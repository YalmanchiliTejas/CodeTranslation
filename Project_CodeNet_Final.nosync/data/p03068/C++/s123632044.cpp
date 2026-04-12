#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(long long int i=0;i<n;++i)
typedef long long int ll;

int main(){

    int n,k;
    string s;
    cin >> n >> s >> k;

    rep(i,n){
        if(s[i]!=s[k-1]){
            s[i]='*';
        }
    }

    cout << s << endl;

    return 0;
}