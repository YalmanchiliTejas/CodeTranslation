#include <iostream>
#include <string>
using namespace std;

int main(void){
    string line;
    cin >> line;
    if ( line == "AAA" || line == "BBB" ){
        cout <<"No\n";
    }else{
        cout <<"Yes\n";
    }
    return 0;
}