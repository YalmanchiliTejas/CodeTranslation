#include <iostream>
using namespace std;
int main() {
    char s[5];
    int i=0;
    cin>>s;
        if((s[i]=='A' && s[i+1]=='A' && s[i+2]=='A')||(s[i]=='B' && s[i+1]=='B' && s[i+2]=='B'))
            cout<<"No";
        else
            cout<<"Yes";
    return 0;
}