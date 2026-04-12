#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    vector<string> s(3);
    for(int i = 0; i<3;i++){
        cin >> s[i];
    }
/*    
    rep(i,3){
        cout << s[i];
    }
    cout << endl;
*/ 
    if(s[0]+s[1]+s[2] == "AAA" || 
        s[0]+s[1]+s[2] == "BBB"){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
}