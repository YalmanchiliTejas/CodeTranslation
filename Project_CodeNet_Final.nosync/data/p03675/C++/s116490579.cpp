#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define rep(i,a,b) for(int (i) = (a); (i) <= (b); i++)
#define repd(i,a,b) for(int (i) = (a); (i) >= (b); i--)
#define foreach(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
#define mp make_pair
#define pb push_back
using namespace std;
#define is_digit(c) ((c) >= '0' && (c) <= '9')
#define is_upper(c) ((c) >= 'A' && (c) <= 'Z')
#define is_lower(c) ((c) >= 'a' && (c) <= 'z')
#define readchar() ((char)fgetc(stdin))
#define printchar(c) fputc((c), stdout)
void readline(char *s) {int len=0;char c;for(c=readchar(); c!='\n'; s[len++]=c, c=readchar());s[len]=0;}
void readstr(char *s) {int len=0;char c;for(c=readchar(); c!=' '&&c!='\n'; s[len++]=c, c=readchar());s[len]=0;}
void printstr(const char *s) {int len=strlen(s);rep(i,0,len-1) printchar(s[i]);}
void to_lower(char *s, int L, int R) {rep(i,L,R) if (is_upper(s[i])) s[i]=s[i]-'A'+'a';}
void to_upper(char *s, int L, int R) {rep(i,L,R) if (is_lower(s[i])) s[i]=s[i]-'a'+'A';}
ll readll() {
	char c;ll ans=0, x=1;for (c=readchar(); !is_digit(c)&&c!='-'; c=readchar());
	if (c=='-') x=-1, c=readchar();for (; is_digit(c); ans=ans*10+c-'0', c=readchar());return ans*x;
}
void printll(ll x) {
	int a[25], cnt=0;if (x==0) { printchar('0'); return; }if (x<0) printchar('-'), x=-x;
	for (; x; a[cnt++]=x-x/10*10, x/=10);repd(i,cnt-1,0) printchar(a[i]+'0');
}
#define readint() ((int)readll())
#define printint(x) printll((ll)(x))
int n, a[200005], b[200005];
int main() {
	n=readint();
	rep(i,1,n) a[i]=readint();
	int x=1, y=n;
	repd(i,n,1) {
		if ((n-i+1)&1) {
			b[x++]=a[i];
		} else {
			b[y--]=a[i];
		}
	}
	rep(i,1,n) {
		printint(b[i]);printchar(' ');}
	return 0;
}
