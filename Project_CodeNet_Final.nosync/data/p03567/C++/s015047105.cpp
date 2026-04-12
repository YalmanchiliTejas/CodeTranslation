#include<bits/stdc++.h>
using namespace std;
string s1;

int main(){
    cin >> s1;
    for(int i = 0; i < s1.length(); i++){
        if(s1[i] == 'A'){
            if(s1[i+1] == 'C') {
                cout << "Yes" << "\n";
                return 0;
            }
        }
    }
    cout << "No" << "\n";
    return 0;
}
