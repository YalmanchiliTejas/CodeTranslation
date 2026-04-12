#include <cstdio>
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include <cmath>
#include <iomanip>
#include <regex>
#include <bits/stdc++.h>
#include <string>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin>>N;
    string S[N];
    for(ll i=0;i<N;i++){
        cin>>S[i];
    }
    map<char,ll> mp[N];
    for(ll i=0;i<N;i++){
        for(ll j=0;j<S[i].length();j++){
            mp[i][S[i][j]] ++;
        }
    }
    for(auto p:mp[0]){
        ll _min=9999999;
        for(ll i=0;i<N;i++){
            _min = min(_min,mp[i][p.first]);
        }
        for(ll i=0;i<_min;i++){
            cout<<p.first;
        }
    }
    cout<<endl;

}
