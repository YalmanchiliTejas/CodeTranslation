#include <iostream>
#include <cmath>
#include <string>
#include <typeinfo>
#include <climits>
#include <algorithm>
#include <cctype>
#include <cstring>
#include <stdio.h>
#include <cstdlib>
using namespace std;

int main(){
    char a;
    cin >> a;
    if(a=='a'||a=='i'||a=='u'||a=='e'||a=='o'){
        cout << "vowel";
    }else{
        cout <<"consonant";
    }
}
