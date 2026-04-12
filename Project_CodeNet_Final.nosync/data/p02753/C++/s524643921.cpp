#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int cnt = 0;
    cin>>s;

    for(int i=0; i<s.size(); i++){
        if(s[i] == 'A') cnt++;
    }

    if(cnt == 3 || cnt == 0) cout<<"No"<<endl;
    else cout<<"Yes"<<endl; 

    return 0;
}