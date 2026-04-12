#include<iostream>

using namespace std;

int main() {
    #ifdef EV
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif

    int t;
    cin>>t;
    t>=30 ? cout<<"Yes\n" : cout<<"No\n";

    return 0;
}