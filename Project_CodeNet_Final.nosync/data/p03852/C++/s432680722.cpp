#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define FOR(i,n) for(int i=0;i<n;i++)
#define PRINT(a) cout<<a<<"\n"
 
int main(){

	char a;

	cin>>a;

	if(a=='a'||a=='e'||a=='i'||a=='o'||a=='u')PRINT("vowel");
	else PRINT("consonant");

	return 0;
}