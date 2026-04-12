#include <algorithm>
#include <iostream>
#include <string>
#include <set>

using namespace std;
int main(void){
    string c;
    cin>>c;
    if (c=="a" or c=="i" or c=="u" or c=="e" or c=="o"){
        puts("vowel");
    }else{
        puts("consonant");
    }
}
