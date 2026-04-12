#include <stdio.h>
#define N 200002
typedef long long LL;

int a[N];
LL s[N][2];

int read()
{
	char c, f = 0;
	while((c = getchar()) < 48 || c > 57){
		if(c == '-') f = 1;
	}
	int x;
	if(!f){
		x = c - 48;
		while((c = getchar()) > 47 && c < 58) x = x * 10 + (c - 48);
	}
	else{
		x = 48 - c;
		while((c = getchar()) > 47 && c < 58) x = x * 10 - (c - 48);
	}
	return x;
}

int main()
{		
	int n, i;
	LL s1 = 0, s2 = 0, t, x;
	
	scanf("%d", &n);
	for(i = 1; i <= n; i++){
		a[i] = read();
	}
	if(n % 2 == 0){
		s[1][0] = (LL)a[1], s[2][0] = (LL)a[2];
		for(i = 3; i <= n; i++){
			if(i & 1){
				s[i][0] = s[i - 2][0] + (LL)a[i];
			}
			else{
				t = s[i - 2][0];
				if((x = s[i - 3][0]) > t) t = x;
				s[i][0] = t + (LL)a[i];
			}
		}
		t = s[n][0];
		if((x = s[n - 1][0]) > t) t = x;
		printf("%lld\n", t);
		return 0;
	}
	
	s[1][0] = (LL)a[1], s[2][0] = (LL)a[2];
	s[3][1] = (LL)a[3], s[3][0] = (LL)(a[1] + a[3]);
	for(i = 4; i <= n; i++){
		if(i & 1){
			s[i][0] = s[i - 2][0] + (LL)a[i];
			t = s[i - 2][1];
			if((x = s[i - 3][0]) > t) t = x;
			if((x = s[i - 4][0]) > t) t = x;
			s[i][1] = t + (LL)a[i];
		}
		else{
			t = s[i - 2][0];
			if((x = s[i - 3][0]) > t) t = x;
			s[i][0] = t + (LL)a[i];
		}
	}
	t = s[n][1];
	if((x = s[n - 1][0]) > t) t = x;
	if((x = s[n - 2][0]) > t) t = x;
	printf("%lld\n", t);
			
	return 0;
}