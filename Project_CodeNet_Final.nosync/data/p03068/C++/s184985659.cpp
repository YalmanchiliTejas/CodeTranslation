#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main()
{
	int N;
	char s[11];
	int k;
	cin >> N;
	cin >> s >> k;
	
	for(int i=0;i<N;i++){
		if(s[i] != s[k-1]) s[i]='*';
	}
	
	cout << s << endl;
	return 0;
}