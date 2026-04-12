#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
const int maxn=5e4+5;
string s;

int main()
{
	cin>>s;
    for(int i=0;i<s.size()-1;i++){
        if((s[i]=='A' && s[i+1]=='B') || (s[i]=='B' && s[i+1]=='A')){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}