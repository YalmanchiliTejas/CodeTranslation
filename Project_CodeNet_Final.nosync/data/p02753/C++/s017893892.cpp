#include<bits/stdc++.h>
using namespace std;
int main(){

    string s;
    cin>>s;
    set<char>c;
    for(int i=0;i<s.size();i++){
        c.insert(s.at(i));
    }
    if(c.size()==2){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }



}







