#include<bits/stdc++.h>
using namespace std;
main(){
    char c,S[] = "aiueo";
    cin >> c;
    if(strchr(S,c)!=NULL)cout << "vowel" << endl;
    else cout << "consonant" << endl;
}