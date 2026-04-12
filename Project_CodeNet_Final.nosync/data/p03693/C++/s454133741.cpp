#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b,c;
    cin>>a>>b>>c;
    int num = 0;
    num = a*100 + b*10 + c;
    if(num%4==0) cout<<"YES";
    else cout<<"NO";
    return 0;
}
