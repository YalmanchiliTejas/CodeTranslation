#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	char s[50];
	
	while (scanf("%s", s), s[0] != '#'){
		
		int len = strlen(s);
		int cnt = 0;
		bool first = true;
		bool key;
		
		for (int i = 0; i < len; i++){
			
			if (first){
				if ('h' <= s[i] && s[i] <= 'p' || s[i] == 'u' || s[i] == 'y'){
					key = true;
				}
				else {
					key = false;
				}
				first = false;
			}
			else if ('h' <= s[i] && s[i] <= 'p' || s[i] == 'u' || s[i] == 'y'){
				if(key);
				else cnt++;
				key = true;
			}
			else {
				if(!key);
				else cnt++;
				key = false;
			}
		}
		
		printf("%d\n", cnt);
	}
	
	return (0);
}