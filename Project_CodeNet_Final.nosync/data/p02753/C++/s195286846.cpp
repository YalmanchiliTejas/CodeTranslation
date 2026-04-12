#include <bits/stdc++.h>
using namespace std;
#define ll long long int


int main(){
    string s; cin >> s;
    for(int i=0;i<2;i++){
        if(s[i]!=s[i+1]){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}