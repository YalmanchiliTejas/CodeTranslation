#include<iostream>
using namespace std;

#define rep(i,n) for(int i=0; i<n; i++)

int main(){
	int s1,s2;
	while( cin >> s1 >> s2, s1||s2 ){
		int ms = s1+s2;
		int mi = 0;
		rep(i,4){
			cin >> s1 >> s2;
			if( ms < s1+s2 ){
				ms = s1 + s2;
				mi = i+1;
			}
		}
		cout << (char)('A'+mi) << " " << ms << endl;
	}
	return 0;
}