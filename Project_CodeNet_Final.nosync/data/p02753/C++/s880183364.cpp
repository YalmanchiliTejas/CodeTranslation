#include <bits/stdc++.h>

using namespace std;

int main()
{
    char s[10];
    while(~scanf("%s",s))
    {
      	int _a=0,_b=0; 
		for(int i=0;s[i];i++){
          if(s[i]=='A') _a++;
          else if (s[i]=='B') _b++;
        }
        printf(_a&&_b?"Yes\n":"No\n");
    }

    return 0;
}
