#include<bits/stdc++.h>
using namespace std;
string s = "aiueo";
int main(){
char inp; scanf("%c", &inp);
if(s.find(inp) != string::npos) cout << "vowel" << endl;
else cout << "consonant" << endl;
return 0;}