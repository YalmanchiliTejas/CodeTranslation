#include <iostream>
#include <string.h>
using namespace std;

int main(){
    string ss;
    cin>>ss;
    if(ss[0]=='A'&&ss[1]=='A'&&ss[2]=='A') {
        cout<<"No";
        return 0;
    }
    if(ss[0]=='B'&&ss[1]=='B'&&ss[2]=='B') {
        cout<<"No";
        return 0;
    }
    cout<<"Yes";
    return 0;

}