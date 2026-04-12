#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;
    if(s[0]!=s[1]||s[1]!=s[2]||s[0]!=s[2]){
        cout<<"Yes"<<endl;
        return 0;
    }
    else{
        cout<<"No"<<endl;
        return 0;
    }
}