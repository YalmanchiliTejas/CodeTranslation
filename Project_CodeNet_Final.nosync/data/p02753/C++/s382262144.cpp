#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    int c1=0,c2=0;
    for(auto it:s) c1+=(it=='A'), c2+=(it=='B');
    if(c1==3 || c1==0) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
	return 0;
}
