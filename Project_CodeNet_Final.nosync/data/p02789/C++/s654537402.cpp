#include<iostream>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    string s;
    if(a == b)
        s = "Yes";
    else
        s = "No";
    cout << s << endl;
    return 0;
}