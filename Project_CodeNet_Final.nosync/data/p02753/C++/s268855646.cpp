#include<bits/stdc++.h>
using namespace std;
int main()
{


    string a;
    cin>>a;
    int cnt=0;
    int cntt=0;
    for(int i=0;i<3;i++)
    {
        if(a[i]=='A') cnt++;
        if(a[i]=='B') cntt++;
    }
    if(cnt!=3&&cntt!=3) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;

    return 0;
}
