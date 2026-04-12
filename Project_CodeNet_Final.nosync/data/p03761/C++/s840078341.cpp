#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <deque>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef unsigned long long int ll;


int main()
{
	int n;
	cin>>n;
	int numOfa = 'a';
	int charArray[26];
	rep(i,26){
		charArray[i] = 50;
	}
	rep(i,n){
		string str;
		cin>>str;
		int charArrayLocal[26] = {0};
		for(int j = 0; j < str.length(); j++){
			charArrayLocal[(int)(str[j] - numOfa)]++;
		}
		/*rep(j,26){
			cout<<(char)(j+'a')<<" "<<charArrayLocal[j]<<endl;
		}*/
		for(int j = 0; j < 26; j++){
			charArray[j] = min(charArray[j],charArrayLocal[j]);
		}
	}
	rep(i,26){
		//cout<<(char)(i+ numOfa)<<" "<<charArray[i]<<endl;
		rep(j,charArray[i]){
			cout<<(char)(i + numOfa);
		}
	}
	cout<<endl;
	return 0;
}

