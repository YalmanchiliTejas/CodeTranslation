#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    bool a = false;
    string s;
    cin>>s;
    for(int k = 1;k<3;k++){
        if(s[k-1] != s[k]) a = true;
    }
    a?cout<<"Yes":cout<<"No";
    return 0;
}
