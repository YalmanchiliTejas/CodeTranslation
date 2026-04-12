#include <bits/stdc++.h>

using namespace std;

string s[2];

int main()
{
    int a,b;
    s[1]="Yes\n";
    s[0]="No\n";
    cin>>a>>b;
    cout<<s[(a==b)]<<"\n";
    return 0;
}
