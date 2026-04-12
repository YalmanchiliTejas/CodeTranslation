#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long 
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL)
//#include "debug.cpp"


int32_t main() 
{ 
    boost;
    
    string s;
    cin>>s;
    int a[2]={0};
    for(int i=0;i<3;i++)
        a[s[i]-'A']++;
    if(a[0]>0 && a[1]>0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
