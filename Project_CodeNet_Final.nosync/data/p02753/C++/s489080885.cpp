#include<bits/stdc++.h>

using namespace std;
string s;
int main(){
    int t=1;while(t--){
        cin >> s ;
        int a=0,b=0;
        for(int i=0;i<3;++i){
            if(s[i]=='A')a++;
            else b++;
        }
        if(a==3 || b==3) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
    return 0;
}