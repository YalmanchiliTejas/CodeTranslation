#include <iostream>
#include <string>
using namespace std;
int main(void){
    // Here your code !
    string str;
    cin >> str;
    int tmp = str.find("AC");
    if(tmp <= str.length()){
        cout <<"Yes" << endl;
    }else{
        cout <<"No" << endl;
    }
    return 0;
    
}
