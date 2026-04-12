#include<bits/stdc++.h>
typedef long long ll;
#define MAXN 6
using namespace std;
char s[MAXN]; 
int main()
{
 cin>>s;
 for(int i=0;i<strlen(s)-1;i++)
 {
  if(s[i]=='A'&&s[i+1]=='C')
  {puts("Yes");return 0;}
 }
 puts("No");
 return 0;
}
