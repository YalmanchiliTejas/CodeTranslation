#include <bits/stdc++.h>
#define INT long long int
using namespace std;
INT n;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin>>s;
    for(int i = 0 ; i < s.size()-1 ; i++ )
        if( s[i] == 'A' and s[i+1] == 'C' ) return cout<<"Yes"<<endl, 0;
    cout<<"No"<<endl;
    return 0;
}
