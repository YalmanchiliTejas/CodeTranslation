#include <iostream>
#include <string>
using namespace std;
int main() {
    char str[3];
    int a=0,b=0;
    cin>>str;
    if (str[0]!=str[1] or  str[0]!=str[2])
        cout<<"Yes";
    else
        cout<<"No";
}