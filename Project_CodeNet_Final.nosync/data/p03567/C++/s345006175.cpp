#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int main(){
    string in;
    cin >> in;
    
    if(in.find("AC")!=-1)
        cout << "Yes" << endl;
        else
            cout << "No" << endl;

    return 0;
}