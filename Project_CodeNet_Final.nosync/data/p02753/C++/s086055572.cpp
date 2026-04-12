#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

int main() {
    string s;
    cin>>s;
    bool flag=false;
    for(int i=0; i<2; i++){
        if(s[i]!=s[i+1])
            flag=true;
    }
    if(flag)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

}
