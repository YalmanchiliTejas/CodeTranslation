#include<bits/stdc++.h>                          
using namespace std;
string s;
int a,b;
int main(){
    cin>>s;
    if(s[0]=='A') a++;
    else b++;
    if(s[1]=='A') a++;
    else b++;
    if(s[2]=='A') a++;
    else b++;
    if(a==1||b==1) cout<<"Yes";
    else cout<<"No";
	return 0;
}