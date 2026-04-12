#include <iostream>
#include <algorithm>
#include <vector>
#define endl "\n"
#define whats(x) cout<<#x<<" is: "<<x<<endl;
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int a=0, b=0;
    for(int i=0; i<3; ++i)
        s[i]=='A'?a++:b++;
    if(a==3||b==3)
        cout<<"No"<<endl;
    else
        cout<<"Yes"<<endl;
    return 0;
}
