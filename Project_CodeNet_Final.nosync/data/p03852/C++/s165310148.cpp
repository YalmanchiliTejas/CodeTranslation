#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<math.h>
#include<queue>
#include<complex>
using namespace std;

long long int solve(long long int n){
	if(n==2){return 3;}
	else if(n==4||n==6||n==9||n==11){return 2;}
	else{return 1;}
}

int main() {
	long long int n=0,m,a,b,c,d,e;
	long double z,w;
	string str,str2,str3;
	char ch;
	long long int x[130]={};
	cout << fixed << setprecision(10);
	cin>>ch;
	if(ch=='a'||ch=='i'||ch=='u'||ch=='e'||ch=='o'){
		cout<<"vowel";
	}else{cout<<"consonant";}



	cout<<endl;
} 
