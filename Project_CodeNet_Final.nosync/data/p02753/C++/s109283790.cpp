#include <bits/stdc++.h>
#include <climits>
#include <cmath>
using namespace std;

int main(void){

    string S;
    cin >> S;
    
    map<char,int> mp;
    
    for(int i = 0; i < S.size();i++)mp[S[i]]++;
    
    string ans = "No";
    if(mp['A']>0 && mp['B']>0)ans = "Yes";

    cout << ans <<endl;
}
