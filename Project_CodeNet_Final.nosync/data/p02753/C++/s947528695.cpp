#include<stdlib.h>
#include<string>
#include <iostream>
using namespace std;
int main() {

    string a;
    cin >> a;
    //a = "AAA";
    bool aflag = false;
    bool bflag = false;
    for (int i = 0; i <= 2; i++) {
        if (a[i] == 'A') { aflag = true; }
        if (a[i] == 'B') { bflag = true; }
    }
    if (aflag and bflag) { printf("Yes"); }
    else { printf("No"); }

}
