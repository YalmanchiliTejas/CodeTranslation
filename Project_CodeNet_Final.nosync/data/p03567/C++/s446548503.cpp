#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map> // STL
#include <string> 
#include <vector>
#include <queue>
#include <stack>
#define mpr make_pair
#define debug() puts("okkkkkkkk")

using namespace std;

typedef long long LL;

const int inf = 1 << 26;

int main(){
	string s;
	cin>>s;
	for(int i=0;i<s.size()-1;i++)if(s[i]=='A'&&s[i+1]=='C'){puts("Yes");return 0;}
	puts("No");

	return 0;
}
