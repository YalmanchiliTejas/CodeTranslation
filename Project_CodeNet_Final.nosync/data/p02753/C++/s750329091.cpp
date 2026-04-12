#include <iostream>
#include <string>
#include <string.h>
#include <vector>
using namespace std;
typedef long long ll;


int main(){
    string S;
    string A = "AAA";
    string B = "BBB";

    //input
    cin >> S;

    if(A.compare(S)  == 0 || B.compare(S) == 0){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }

    return 0;
}
