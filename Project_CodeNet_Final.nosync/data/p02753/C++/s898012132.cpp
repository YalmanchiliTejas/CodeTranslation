#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define ll long long
using namespace std;

const ll mod = 1e9 + 7;

ll C[2005][2005];
ll dp[100005][13];


int main(){
    string S;
    cin >> S;
    if(S == "AAA" || S == "BBB" ) cout << "No" << endl;
    else cout << "Yes" << endl;
}