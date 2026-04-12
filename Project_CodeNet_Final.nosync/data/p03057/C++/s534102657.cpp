#include<bits/stdc++.h>
#define ll long long
#define lld long double
using namespace std;
const int N = 101000;
char c[N];
int main(){
	sprintf(c,"p=int(1e9+7)\ndef calc(n,l,r):\n\tf=[0]* (n+1)\n\tf[0]=1\n\tsum=0\n\tfor i in range (1,n+1):\n\t\tif i>=l:\n\t\t\tsum+=f[i-l]\n\t\tf[i]=sum%%p\n\t\tif (i>=r):\n\t\t\tsum-=f[i-r]\n\tans=0\n\tfor i in range (l,r+1):\n\t\tans=(ans+f[n-i]*i)%%p\n\treturn ans\nn,m=input().split()\nn=int(n)\nm=int(m)\ns=input()\na=s.split(chr(ord('R')+ord('B')-ord(s[0])))\nif len(a)==1:\n\tprint((calc(n,2,n)+1)%%p)\nelif n%%2==1:\n\tprint(0)\nelse:\n\tr=len(a[0])+1-len(a[0])%%2\n\tfor i in range(1,len(a)-1):\n\t\tif len(a[i])%%2==1 :\n\t\t\tr=min(r,len(a[i]));\n\tn=n//2\n\tr=(r+1)//2\n\tprint(calc(n,1,r)*2%%p)\n");
	string out;
	out="python3 -c \"";
	int len=strlen(c);
	for(int i=0;i<len;i++)
		out+=c[i];
	out+="\"";
	system(out.data());
	return 0;
}

