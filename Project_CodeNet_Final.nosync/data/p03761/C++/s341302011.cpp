#include <iostream>
#include <utility>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;
	int c['{'][52]={};
	string temp;
	char t;
	string ans="";
	for (int i=0;i<n;i++){
		cin >> temp;
		for (int j=0;j<temp.length();j++){
			c[temp[j]][i]++;
		}
	}
	int a,b;
	for (char j='a';j<='z';j++){
		b=2147483647;
		for (int i=0;i<n;i++){
			a=c[j][i];
			if (a<b){
				b=a;
			}
		}
		if (b!=0){
			for (int o=1;o<=b;o++){
				ans=ans+j;	
			}
		}
	}
	cout << ans;
	return 0;
}