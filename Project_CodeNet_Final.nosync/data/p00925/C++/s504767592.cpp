#include <cstdio>
#include <cstring>

using namespace std;

char s[25];
int n, l; 

int calc1(){
	char last = '+';
	int l = strlen(s);
	int ret = 0; 
	for(int i = 0; i < l; i += 2){
		int d = s[i] - '0';
		if(last == '+') ret += d;
		else ret *= d;
		last = s[i + 1]; 
	}
	return ret;
} 

int calc2(){
	char last = '*';
	int ret = 0, mul = 1;
	int l = strlen(s);
	for(int i = 0; i < l; i += 2){
		int d = s[i] - '0';
		if(last == '+') ret += mul, mul = d;
		else mul *= d;
		//printf("mul = %d ret = %d\n", mul, ret);
		last = s[i + 1];
	} 
	ret += mul;
	return ret;
}

int main(){
	while(scanf("%s%d", s, &n) == 2) {
		int l = strlen(s); s[l] = '+'; s[l + 1] = 0; 
		int ans1 = calc1(), ans2 = calc2();
		//printf("%d %d\n", ans1, ans2);
		if(ans1 == n && ans2 == n) puts("U");
		else if(ans1 != n && ans2 != n) puts("I");
		else if(ans1 == n) puts("L");
		else puts("M"); 
		
	}
	return 0;
} 