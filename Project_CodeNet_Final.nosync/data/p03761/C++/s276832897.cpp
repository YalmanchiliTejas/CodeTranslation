#include <vector>
#include <iostream>
#include <cmath>
#include <numeric>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
    int n,a[26];
    char c[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    cin >> n;
    vector<string>s(n);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=0;i<26;i++){
        int b=51,d;
        for(int j=0;j<n;j++){
            d=count(s[j].begin(),s[j].end(),c[i]);
            b=min(b,d);
        }
        a[i]=b;
    }
    for(int i=0;i<26;i++){
        for(int j=0;j<a[i];j++){
            cout<<c[i];
        }
    }
}