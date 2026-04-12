#include <iostream>
#include <fstream>
 
#include <vector>
 
using namespace std;
 
int main(){
 
    int X;
 
    string res = "NO";
 
    cin >> X;
 
    //X * t = T
    //t = T/X
 
    if(X == 3 || X == 5 || X == 7)res = "YES";
 
    cout << res << endl;
 
}
 