#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)


int main(){
    char c;
    cin>>c;
    vector<char> a={'a','i','u','e','o'};
    bool ok=0;
    rep(i,5){
        if(a[i]==c) ok=1;
    }
    if(ok) cout<<"vowel"<<endl;
    else cout<<"consonant"<<endl;
}