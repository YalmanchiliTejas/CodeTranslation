#include <bits/stdc++.h>
using namespace std;
int main(void){
    char x;
    cin>>x;
    string s="aeiou";
    cout<<(s.find(x)==string::npos?"consonant":"vowel")<<endl;
}
