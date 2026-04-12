#include<bits/stdc++.h>
using namespace std;

int main(void){
    int X,Y,Z,ans;
    cin>>X>>Y>>Z;

    Y+=Z;
    X-=Z;
    ans=X/Y;

    cout<<ans<<endl;
    return 0;
}
