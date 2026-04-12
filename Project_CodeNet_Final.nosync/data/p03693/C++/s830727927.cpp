#include <bits/stdc++.h>
using namespace std;
int main()
{
    int r,g,b;
    cin>>r>>g>>b;

    r=r*100;
    g=g*10;
    int ans=r+g+b;

    if(ans%4==0){
        cout<<"YES"<<endl;
    }else{

    cout<<"NO"<<endl;
    }

    return 0;
}
