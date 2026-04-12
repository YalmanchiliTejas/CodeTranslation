/*
      author : nishi5451
      created: 11.08.2020 00:04:02
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    char c;
    cin >> c;
    if(c=='a' || c=='i' || c=='u' || c=='e' || c=='o')  
        cout << "vowel" << endl;
    else cout << "consonant" << endl;
    return 0;
}