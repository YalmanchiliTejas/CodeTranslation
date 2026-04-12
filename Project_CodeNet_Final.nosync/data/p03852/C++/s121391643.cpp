// luogu-judger-enable-o2
#include<iostream>
using namespace std;
char a[10]{'a','e','i','o','u'};
int z=0;
int main(){
char b;
cin>>b;
for(int i=0;i<5;i++){
	if(b==a[i])z++;
}
	if(z!=0)cout<<"vowel";
	else cout<<"consonant";
	return 0;
}