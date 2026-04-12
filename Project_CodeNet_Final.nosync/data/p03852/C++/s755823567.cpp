// A - 居合を終え、青い絵を覆う / UOIAUAI
#include <bits/stdc++.h>
using namespace std;

int main(){
	char c; cin>>c;
	cout<< (string{"aeiou"}.find(c)!=string::npos? "vowel":"consonant") <<endl;
}