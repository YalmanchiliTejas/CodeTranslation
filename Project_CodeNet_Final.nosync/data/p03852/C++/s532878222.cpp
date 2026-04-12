#include <bits/stdc++.h>
//#include <iostream>
//#include <cstdio>

#define repl(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repl(i, 0, n)
#define MOD 1000000007
#define INF 2000000000

typedef long long ll;
typedef unsigned long long ull;
//typedef Pair<int,int> P;

using namespace std;

int main(void){
	char c;
	cin>>c;
	if(c=='a'||c=='i'||c=='u'||c=='e'||c=='o'){
		cout<<"vowel"<<endl;
	}else{
		cout<<"consonant"<<endl;
	}
	
	return 0;
}