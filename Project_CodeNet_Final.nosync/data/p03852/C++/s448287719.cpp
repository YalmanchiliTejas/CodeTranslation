#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
using namespace std;

int main(){
    char c;
    cin>>c;
    if(c=='a'||c=='i'||c=='u'||c=='e'||c=='o'){
        cout<<"vowel"<<endl;
    }
    else{
        cout<<"consonant"<<endl;
    }
    return 0;
}
