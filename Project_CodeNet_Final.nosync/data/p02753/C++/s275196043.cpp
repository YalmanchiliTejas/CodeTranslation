#include<iostream>
#
using namespace std;

int main(void)

{
    string s;
    cin>>s;
    if((!s.compare("AAA"))||(!s.compare("BBB"))){
        cout<<"No\n";
    }
    else
        cout<<"Yes\n";
    return 0;
}
