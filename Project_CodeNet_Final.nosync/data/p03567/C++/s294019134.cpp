#include<bits/stdc++.h>

using namespace std;

#define ll long long


int main() {
    string s;
    cin>>s;
    if(s.size()<2) {
        cout<<"No\n";
        return 0;
    }
    int n=s.size();
    for(int i=0;i<n-1;i++) {
        if(s[i]=='A' && s[i+1]=='C') {
            cout<<"Yes\n";
            return 0;
        }
    }
    cout<<"No\n";
    
    return 0;
}
