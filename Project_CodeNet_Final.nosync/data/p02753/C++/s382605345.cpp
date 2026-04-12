#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string str;
    cin>>str;
    map<char,ll> m1;
    for(ll i=0;i<str.length();i++)
        m1[str[i]]+=1;
    if(m1['A']>0 && m1['B']>0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
