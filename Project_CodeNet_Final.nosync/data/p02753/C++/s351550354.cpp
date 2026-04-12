#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
int main(void){
    
    char s[3];
    const char a[] = "A";
    const char b[] = "B";
    
    cin >> s;
    
    if ( strstr(s,a) && strstr(s,b) ) {
        cout << "Yes" << endl;   
    } else {
    	cout << "No" << endl;
    }
    
    return 0;
}
