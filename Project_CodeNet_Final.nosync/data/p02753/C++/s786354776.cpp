#include <bits/stdc++.h>
using namespace std;

int main(){
    string ss;
    cin >> ss;
    if(ss[0]=='A'){
        for(int i=1; i<ss.length(); i++){
            if(ss[i]=='A')
                continue;
            else{
                cout << "Yes";
                return 0;
            }
        }
    }
    if(ss[0]=='B'){
        for(int i=1; i<ss.length(); i++){
            if(ss[i]=='B')
                continue;
            else{
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
    return 0;
}