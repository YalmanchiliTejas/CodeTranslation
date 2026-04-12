#include<bits/stdc++.h>
#define __ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll long long int
#define N 100005

using namespace std;

int main()
{
    __

    string s;
    int a=0,b=0;

    cin>>s;

    for(int i=0;i<3;i++){
        if(s[i]=='A') a++;
        else b++;
    }

    if(a>0 && b>0) cout << "Yes";

    else cout << "No";
    return 0;
}
