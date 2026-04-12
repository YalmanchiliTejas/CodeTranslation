#include <bits/stdc++.h>
using namespace std;
string s;
bool flag;
int main(){
    cin>>s;
    for(int i = 0; i < s.size()-1; i++){
        if(s[i]=='A' and s[i+1] == 'C')flag = true;
    }
    if(flag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
