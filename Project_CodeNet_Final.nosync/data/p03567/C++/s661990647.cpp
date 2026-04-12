#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    string s; cin>>s;
    int n=s.length();

    string ans="No";
    for(int i=0;i<n-1;i++){
        if(s[i]=='A' and s[i+1]=='C') ans="Yes";
    }
    cout<<ans<<endl;
    return 0;
}
