#include<iostream>
using namespace std;
int main() {
    int r,g,b,ans;
    while(cin>>r>>g>>b) {
        ans=r*100+g*10+b;
        if(ans%4!=0)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}
