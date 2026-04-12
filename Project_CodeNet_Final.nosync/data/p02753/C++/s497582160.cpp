#include <bits/stdc++.h>
using namespace std;


#define ll long long
#define pb push_back
#define mp make_pair

int main() {
    string s;
    cin >> s;
    ll ca=0,cb=0;
    for(ll i=0;i<3;i++)
    {
        if(s[i]=='A')
        ca++;
        else
        cb++;
    }
    
    if(ca!=0 &&  cb!=0)
    cout <<"Yes" <<endl;
    else
    cout << "No"<<endl;
}