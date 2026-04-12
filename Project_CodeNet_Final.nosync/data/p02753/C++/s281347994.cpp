#include<bits/stdc++.h>
#define lli long long int
using namespace std;
int main()
{
    string str;
    cin >> str;
    lli ans=0,sum=0;
    if(str[0]=='A'||str[1]=='A'||str[2]=='A')   ans=1;
    if(str[0]=='B'||str[1]=='B'||str[2]=='B')   sum=1;
    if(sum&ans) cout << "Yes" << endl;
    else    cout << "No" << endl;
    
    return 0;
}