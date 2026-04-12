#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    string s;cin>>s;
    int c = 0;
    for(int i=0;i<s.length();i++){
        if(s[i] == 'A') c++;
    }
    if(c == 0 || c== 3) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    return 0;
}