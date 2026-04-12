#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <string>
#include <stack>
#include <set>
#include <deque>
#define mp make_pair
using namespace std;
string str;
int main(){
	cin>>str;
	for (int i=0;i<=str.length()-2;i++){
		if (str[i]=='A' && str[i+1]=='C'){
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
	return 0;
}