#include <stdio.h>
#include <string.h>


int main() 
{
	int k, a, b, c, ans, l, x, y, z, i, j;
	char s[111];
	
	scanf("%s%d", s, &k);
	l = strlen(s);
	if(k == 1){
		ans = 9 * (l - 1), x = s[0] - 48;
		for(a = 1; a <= 9; a++){
			if(a <= x) ans++;
		}
	}
	else if(k == 2){
		if(l < 2) ans = 0;
		else{
			ans = 9 * 9 * (l - 1) * (l - 2) / 2;
			x = s[0] - 48;
			for(i = 1; i < l && s[i] == 48; i++);
			if(i < l) y = s[i] - 48;
			for(a = 1; a <= x; a++){
				for(b = 1; b <= 9; b++){
					if(a < x) ans += l - 1;
					else if(i < l){
						if(b <= y) ans += l - i;
						else ans += l - i - 1;
					}
				}
			}
		}
	}
	else{
		if(l < 3) ans = 0;
		else{
			ans = 9 * 9 * 9 * (l - 1) * (l - 2) * (l - 3) / 6;
			x = s[0] - 48;
			for(i = 1; i < l && s[i] == 48; i++);
			if(i < l) y = s[i] - 48;
			for(j = i + 1; j < l && s[j] == 48; j++);
			if(j < l) z = s[j] - 48;
			for(a = 1; a <= x; a++){
				for(b = 1; b <= 9; b++){
					for(c = 1; c <= 9; c++){
						if(a < x) ans += (l - 1) * (l - 2) / 2;
						else if(i < l){
							if(i + 1 == l) continue;
							ans += (l - i - 1) * (l - i - 2) / 2;
							if(b < y) ans += l - i - 1;
							else if(b == y && j < l){
								if(c <= z) ans += l - j;
								else ans += l - j - 1;
							}
						}
					}
				}
			}
		}
	}
	printf("%d\n", ans);	
			
	return 0;
}