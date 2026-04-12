#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define endl '\n'
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int main()
{
    FASTINOUT;
    int x,k;
    string s;
    cin>>x>>s>>k;
    k--;
    char a=s[k];
    for (int i=0;i<x;i++){
        if (s[i]!=a)
            cout<<'*';
        else
            cout<<a;
    }
    return 0;
}
