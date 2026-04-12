#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0;i<int(n);i++)
#define _GLIBCXX_DEBUG

int main(){
    int n;
    cin>>n;
    vector <int> hs(n);
    rep(i,n) {
        cin>>hs[i];
    }
    int count=0;
    int max=0;
    rep(i,n) {
        if (hs[i]>=max) {
            max=hs[i];
            count+=1;
        }
    }
    cout<<count<<endl;
}