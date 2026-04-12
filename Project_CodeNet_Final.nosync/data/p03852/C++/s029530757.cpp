// 居合を終え、青い絵を覆う
#include <iostream>
using namespace std;

char vowel[5]={'a','i','u','e','o'};

int main(){
    char c;
    cin>>c;
    bool b=false;
    for(int i=0;i<5;i++){
        if(c==vowel[i]) b=true;
    }
    cout<<(b?"vowel":"consonant")<<endl;
    return 0;
}