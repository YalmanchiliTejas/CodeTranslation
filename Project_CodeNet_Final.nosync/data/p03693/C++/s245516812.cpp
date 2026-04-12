#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    int r,g,b;
    cin>>r>>g>>b;
    int d=10*g+b;
    if(d%4==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}

