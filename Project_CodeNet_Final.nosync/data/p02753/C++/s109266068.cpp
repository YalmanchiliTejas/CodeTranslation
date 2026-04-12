#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
#include<iomanip>
using namespace std;

typedef long long ll;

int MOD=1000000007;


int main(){
    int a=0,b=0;
    string S;
    cin >> S;
    for(ll i=0; i<S.size(); i++){
        if(S[i]=='A') a++;
        if(S[i]=='B') b++;
    }
    if(a==0 || b==0) cout << "No" << endl;
    else cout << "Yes" << endl;
}
