#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
int main(){
cin.tie(0);
ios::sync_with_stdio(false);

	char s;
	cin>>s;
	if(s=='a' || s=='i' || s=='e' || s=='o' || s=='u')
		cout<<"vowel"<<endl;
	else
		cout<<"consonant"<<endl;
		
	return 0;
}