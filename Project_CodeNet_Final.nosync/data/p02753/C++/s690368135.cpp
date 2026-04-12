#include<bits/stdc++.h>
using namespace std;
int main(){
    //#ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
    //#endif
    string ch;
    cin>>ch;
    if (ch[0]!=ch[1])
        cout<<"Yes";
    else if (ch[0]!=ch[2])
        cout<<"Yes";
    else if (ch[1]!=ch[2])
        cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
