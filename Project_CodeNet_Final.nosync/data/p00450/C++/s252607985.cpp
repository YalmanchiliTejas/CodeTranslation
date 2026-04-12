#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
#define MAX 100010

int main(){
	int a[MAX], b[MAX], c[MAX], n;
	while(cin >> n, n){
		fill(a, a+MAX, 0);
		fill(b, b+MAX, 0);
		int x, w = 0, d = 0;
		
		int flag;
		for(int i = 1;i <= n;i++){
			cin >> x;c[i] = x;
			if(i == 1)flag = x;
			
			if(i%2 == 0){	//??¶??°
				if(x && !c[i-1]){
					a[w--] = 0;
					b[d--] = 0;
					if(w == -1)w = 0;
					if(d == -1)d = 0;
				}
				if(!x && c[i-1]){
					b[d--] = 0;
					a[w--] = 0;
					if(w == -1)w = 0;
					if(w == -1)d = 0;
				}
			}
			if(x){if(flag)d++, flag = 0;b[d] = i;}
			if(!x){if(!flag)w++, flag = 1;a[w] = i;}
		}
		
		int ans = 0;
		if(a[1] < b[1]){
			ans = a[1];
			for(int i = 2;i <= w;i++)ans += a[i] - b[i-1];
		}else for(int i = 1;i <= w;i++)ans += a[i] - b[i];
		cout << ans << endl;
		
	}
	
	return 0;
}