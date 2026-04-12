#include <bits/stdc++.h>
using namespace std;
string divide[4]={"dream","dreamer","erase","eraser"};
int main(){
    int r,g,b;
    cin>>r>>g>>b;
    int x=100*r+10*g+b;
    if(x%4==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}