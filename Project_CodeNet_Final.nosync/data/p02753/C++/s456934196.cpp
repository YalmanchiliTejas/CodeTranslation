#include <iostream>
#include <string>

using namespace std;

int main(void){
    string a;
    cin >> a;
    if(a[0]==a[1]&&a[1]==a[2])
        cout << "No";
    else
        cout << "Yes";
    return 0;
}