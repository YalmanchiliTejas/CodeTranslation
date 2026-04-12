#include <iostream>
using namespace std;
int main(void){
    string a;
    cin>>a;
    if(a.compare("AAA")==0 || a.compare("BBB")==0){
        cout<<"No";
    }else cout<<"Yes";
}
