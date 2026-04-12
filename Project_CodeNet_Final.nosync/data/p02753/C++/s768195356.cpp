#include <bits/stdc++.h>
using namespace std;
int main(){
    char c,a=0;
    for(int i=0;i<3;i++)cin>>c,a+='C'-c;
    cout<<(a%3?"Yes":"No")<<endl;
}
