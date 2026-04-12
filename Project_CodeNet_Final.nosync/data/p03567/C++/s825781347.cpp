#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <functional>
#include <set>
#include <queue>
#include <cctype>
#include <climits>
#include <stack>
#include <map>
#include <cstring>
 
using namespace std;

int main(){

	string s;
	cin>>s;

	for(int i=0;i<s.size()-1;i++){
		if(s[i]=='A' && s[i+1]=='C'){
			cout<<"Yes"<<endl;
			return 0;
		}
	}

	cout<<"No"<<endl;

	return 0;
}
