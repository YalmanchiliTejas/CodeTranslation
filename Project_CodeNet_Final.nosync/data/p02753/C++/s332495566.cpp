#include<bits/stdc++.h>
#define ls rt<<1
#define rs rt<<1|1
using namespace std;

typedef long long ll;
const int N=1e5+5;
const ll p=1000000007;

int main()
{
    string s;
    cin>>s;
    if(s[0]==s[1]&&s[1]==s[2])
        cout<<"No"<<endl;
    else
        cout<<"Yes"<<endl;
}