
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main(){
	/*input*/
	int n;
	cin >> n;
	char s[11];
	cin >> s;
	int k;
	cin >> k;
	/*calc*/
//    int  ans = 0;
    char key = s[k-1];
    for(int i = 0; i < n; i++){
    	if(s[i] == key) continue;
    	s[i] = '*';
    }
    /*output*/
	   	cout<< s <<endl;
//	   	cout<< ans <<endl;
    return 0;
}
