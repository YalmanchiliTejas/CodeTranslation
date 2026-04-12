#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#define MOD 1000000007
using namespace std;
int main(void){
    // Your code here!
    int n,k;
    string s;
    
    cin >> n >> s >> k;
    
    for(int i=0;i < n;i++){
        if(s[i]!=s[k-1]) s[i]='*';
    }
    
    cout << s << endl;
    
}
