#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int sum=0;
    for(int i=1;i<3;++i){
        if(s.at(i)==s.at(i-1))sum++;
    }
    if(sum==2)cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
}