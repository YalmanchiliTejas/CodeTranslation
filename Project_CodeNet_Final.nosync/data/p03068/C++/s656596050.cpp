#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
#define rep2(i,s,n) for(long long i=(s); i<(long long)(n);i++)
#define mod 1000000007

int main() {
    int n,k;
    string s;
    cin>>n>>s>>k;


    for (int i=0;i<s.size();i++) {
        if(s[i]!=s[k-1]){
            s[i]='*';
        }
    }

    cout<<s<<endl;
}
