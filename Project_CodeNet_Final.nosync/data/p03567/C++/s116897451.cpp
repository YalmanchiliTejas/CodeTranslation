#include <bits/stdc++.h>
 
#define FI(i,a,b) for(int i=(a);i<=(b);i++)
#define FD(i,a,b) for(int i=(a);i>=(b);i--)
 
#define LL long long
#define Ldouble long double
#define PI 3.14159265358979323846264338327950288419
 
#define PII pair<int,int>
#define PLL pair<LL,LL>
#define mp make_pair
#define fi first
#define se second
 
using namespace std;
 
char s[10];
int len;
 
int main(){
        cin.getline(s, 10);
	len = strlen(s);
	FI(i, 1, len - 1){
		if(s[i] == 'C' && s[i - 1] == 'A'){
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}