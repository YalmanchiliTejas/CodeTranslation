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
const ll MOD = 1000000007; 
using plong = pair<ll,ll>;


int main(){
    string S;
    cin>>S;
    bool flag=true;
    if(S[0]==S[1]&&S[2]==S[1]){
        flag = false;
    }
    cout<<(flag?"Yes":"No")<<endl;
}
