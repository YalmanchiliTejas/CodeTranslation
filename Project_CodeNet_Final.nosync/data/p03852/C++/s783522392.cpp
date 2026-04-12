#include<iostream>
using namespace std;
 
int main(){
    char c;
    cin >> c;
    puts((c=='a'||c=='e'||c=='i'||c=='o'||c=='u'?"vowel":"consonant"));
    return 0;
}