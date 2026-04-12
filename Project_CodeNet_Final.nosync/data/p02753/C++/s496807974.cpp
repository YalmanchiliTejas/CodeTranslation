#include <iostream>
#include <string>
using namespace std;
int main(){
    string in;
    cin >> in;
    int flag = 0;
    if(in[0] == in[1] && in[1] == in[2]) cout << "No";
    else cout << "Yes";
    return 0;
}
