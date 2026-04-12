#include <bits/stdc++.h>
using namespace std;
int main() {
    set<char> s;
    for(int i=1;i<=3;i++) {
        char c;
        cin>>c;
        s.insert(c);
    }
    if(s.size()==1) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    return 0;
}