#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define all(x) (x).begin(), (x).end()
#define PI 3.14159265358979323846264338327950L
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    int n;
    cin>>n;
    vector<int> A(26,50);
    rep(i,n){
        string S;
        cin>>S;
        vector<int> B(26,0);
        for(auto c:S) B[c-'a']++;
        rep(i,26) A[i]=min(A[i],B[i]);
    }
    rep(i,26){
        rep(j,A[i]){
            cout<<(char)(i+'a');
        }
    }
    cout<<endl;
}