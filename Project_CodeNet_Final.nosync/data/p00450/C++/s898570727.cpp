#include<iostream>
#include<cstdio>

#define MAX 100020
using namespace std;

class Stack{
	int *t;
	int high;
public:
	Stack(int sz):high(1){ t = new int[sz]; t[0] = 0; }
	~Stack(){ delete [] t; }
	void push(const int &p){
		t[high] = p;
		++high;
	}
	int pop(){
		int ret = t[high-1];
		--high;
		if( high < 1 ) high = 1;
		return ret;
	}
	int top(){
		return t[high-1];
	}
};

int main(){
	while(true){
		int n;
		int ans = 0;
		int most_right_white = 0;
		int most_right_black = 0;
		int a[MAX] = {0,};

		scanf("%d", &n);
		if( n == 0 )
			break;

		for(int i = 1; i <= n; ++i){
			int c;
			
			scanf("%d", &c);

			if( i % 2 == 0 ){
				if( c == 0 ){
					if( a[i-1] != c ){
						for(int d = most_right_white + 1; d < i; ++d){
							a[d] = c;
						}
						most_right_black = 0;
						for(int d = most_right_white - 1; d > 0; --d){
							if( a[d] == 1 ){
								most_right_black = d;
								break;
							}
						}
					}
				}else{
					if( a[i-1] != c ){
						for(int d = most_right_black + 1; d < i; ++d){
							a[d] = c;
						}
						most_right_white = 0;
						for(int d = most_right_black - 1; d > 0; --d){
							if( a[d] == 0 ){
								most_right_white = d;
								break;
							}
						}
					}
				}
			}
			a[i] = c;
			if( c == 0 ){
				most_right_white = i;
			}else{
				most_right_black = i;
			}
		}
		ans = 0;
		for(int i = 1; i <= n; ++i){
			if( a[i] == 0 ) ++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}