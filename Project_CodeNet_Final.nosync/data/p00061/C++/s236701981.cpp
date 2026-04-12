#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#define n 100
using namespace std;
int main(){
	int a[n],b[n];
	int c = 0;
	int d,e;
	char f;
	while(1){
		cin >> d >> f >> e;
		if(d+e==0) break;
		a[c] = d;
		b[c] = e;
		c++;
	}
	while(1){
		bool out = true;
		for(int i=0;i<c-1;i++){
			if(b[i]<b[i+1]){
				out = false;
				int t = b[i];
				b[i] = b[i+1];
				b[i+1] = t;
				t = a[i];
				a[i] = a[i+1];
				a[i+1] = t;
			}
		}
		if(out) break;
	}
	while(cin >> d){
		int s = 1;
		int t = b[0];
		for(int i=0;i<c;i++){
			if(b[i]!=t){
				t = b[i];
				s++;
			}
			if(d==a[i]) break;
		}
		cout << s << endl;
	}
}