#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
main(){
    char c,S[] = "aiueo";
    cin >> c;
    if(strchr(S,c)!=NULL)cout << "vowel" << endl;
    else cout << "consonant" << endl;
}