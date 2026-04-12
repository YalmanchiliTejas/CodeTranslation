#include<cstdio>
#include<iostream>
#include<ctype.h>
#include<string>
using namespace std;
int main(){
	int n, c = 1;
	cin >> n;
	int h[n];
	for(int i = 0; i < n; i++){
		cin >> h[i];
	}
	for(int i = 1; i < n; i++){
		for(int s = 0; s < i; s++){
			if(s == i - 1){
				if(h[i] >= h[s]){
					c++;
				}
				else{
					break;
				}
			}
			else if(h[i] >= h[s]){
				continue;
			}
			else{
				break;
			}
		}
	}
	cout << c << endl;
	return 0;
}