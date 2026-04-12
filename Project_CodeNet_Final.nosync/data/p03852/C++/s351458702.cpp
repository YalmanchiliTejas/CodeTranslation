#include <bits/stdc++.h>
using namespace std;
int main(){
//元音指a,e,i,o,u
	char a;
	cin>>a;
	if(a=='a'||a=='e'||a=='i'||a=='u'||a=='o'){
		cout<<"vowel";
	}
	else{
		cout<<"consonant";
	}
	return 0;
}