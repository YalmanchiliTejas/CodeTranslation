#include <bits/stdc++.h>
using namespace std;
int main(){
    char c;
    cin>>c;
    string vowels="aiueo";
    cout<<(vowels.find_first_of(c)!=string::npos?"vowel":"consonant")<<endl;
}
