#include <iostream>
using namespace std;

int main(void){
    char c;
    cin>>c;
    string s="aiueo";
    cout<<(s.find(c)!=string::npos?"vowel":"consonant")<<endl;
}