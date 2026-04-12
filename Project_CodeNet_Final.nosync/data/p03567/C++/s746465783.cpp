#include<cstdio>
#include<map>
#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
#include<vector>
#include<cmath>
using namespace std;

char s[1000];

int main(){
	cin >> s + 1;
	int len = strlen(s + 1);
	for(int i = 1;i <= len;i++){
		if(s[i] == 'A' && s[i + 1] == 'C'){
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
}