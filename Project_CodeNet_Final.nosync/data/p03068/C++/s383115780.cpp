#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    int k,n;
    string s;
    cin >> n >> s >> k;
    
    for (int i=0;i<n;i++){
    if (s[i] != s[k-1]) s[i] = '*';
    }
    
    cout <<  s << endl;
}
