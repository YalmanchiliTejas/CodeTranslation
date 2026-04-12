#include<bits/stdc++.h>
using namespace std;

string s;
bool bus = false;

int main(){
    cin >> s;

    for(int i=0; i<2; i++){
        for(int j=i+1; j<3; j++){
            if(s[i] != s[j]) bus = true;
        }
    }
    if(bus) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}