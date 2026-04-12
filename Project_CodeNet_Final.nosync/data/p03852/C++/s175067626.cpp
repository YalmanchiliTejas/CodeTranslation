#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <cctype>
#include <algorithm>
using namespace std;
int main(void){
    char c ;
    cin >> c ;

    if(c == 'a'||c == 'u'||c == 'o'||c == 'e'||c == 'i'){
        cout << "vowel" << endl;
    }else{
        cout << "consonant" << endl;
    }

    return 0;
}