#include <iostream>
#include <string>

using namespace std;

int main(){
    string s;
    cin>>s;
    for (int i=0; i<s.size(); i++) {
        if (s.at(i)=='A' && s.at(i+1)=='C') {
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}