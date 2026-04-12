#include "bits/stdc++.h"

using namespace std;

using ll = long long;

int main(){
    string s;
    cin>>s;
    for(int i=0;i<s.length()-1;++i){
        if(s[i]=='A' && s[i+1]=='C'){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
}