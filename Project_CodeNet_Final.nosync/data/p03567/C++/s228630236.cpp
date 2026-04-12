#include<bits/stdc++.h>
using namespace std;


string s;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s.substr(i,2)=="AC"){
            return cout<<"Yes",0;
        }
    }
    cout<<"No";
}
