#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin>>n;
    while(n != 0){
        int s[n], sum=0;
        for(int i=0; i<n; i++) cin>>s[i], sum+=s[i];
        sort(s, s+n);
        cout << (sum-s[0]-s[n-1])/(n-2) << endl;
        cin >> n;
    }
}

