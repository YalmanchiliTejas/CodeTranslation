#include <bits/stdc++.h>  
using namespace std;  
#define INF 0x3f3f3f3f  
typedef long long ll;  
const int N = 551;  
char s[N];
int main()  
{  
  //  freopen("in.txt", "r", stdin);
    int n;
    while (~scanf("%d", &n))
    {
    	int rec[26] = {0};
    	for (int i = 0; i < 26; i++)
    		rec[i] = 100;
    	for (int i = 0; i < n; i++)
    	{
    		int tmp[26] = {0};
    		scanf("%s", s);
    		for (int j = 0; s[j]; j++)
    			tmp[s[j] - 'a']++;
    		for (int j = 0; j < 26; j++)
    			rec[j] = min(rec[j], tmp[j]);
    	}
    	for (int i = 0; i < 26; i++)
    	{
    		for (int j = 0; j < rec[i]; j++)
    			printf("%c", i + 'a');
    	}
    	putchar('\n');
    }
  
   return 0;  
}  