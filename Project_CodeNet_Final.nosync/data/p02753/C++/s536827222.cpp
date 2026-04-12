#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main (void) {
    string s;
    cin >> s;
    string ret;
    ret = "No";
    for(int i=0;i<s.size()-1;i++){
        if(s[i] != s[i+1]){
            ret = "Yes";
            break;
        }
    }
    cout << ret << endl;

    return 0;
}