#include<iostream>
#include<cstdio>
using namespace std;
char c;
bool check()
{
    return c=='a'||c=='i'||c=='u'||c=='e'||c=='o';
}
void solve()
{
    if(check())puts("vowel");
    else puts("consonant");
    return ;
}
main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>c;
    solve();
    return 0;
}