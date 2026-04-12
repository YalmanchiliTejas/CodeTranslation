#include <iostream>
#include <string>

using namespace std;

int main(){
    string S;
    cin >> S;

    if(S == "AAA" || S=="BBB"){
        cout << "No" << endl;
        exit(0);
    } 

    cout << "Yes" << endl;
}