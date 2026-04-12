#include<bits/stdc++.h>
using namespace std;
 
/* data type, special numbers, defines */
//#define int ll //use if ded
#define ll long long
#define ld long double
const ll inf=LLONG_MAX;
//const ll mod=1e9+7;
const ll mod=998244353;
const ld pi=acos(-1.0);
#define all(v) v.begin(), v.end()
/* end data type and special numbers */
 
/* fast input.output */
#define gc getchar//_unlocked
#define pc putchar//_unlocked
#define endl pc('\n')
int get_i(){
	char c=gc(); bool neg=false;
	for(; c<'0'||'9'<c; c=gc())
		if(c=='-') neg=true;
	int rs=c-'0'; c=gc();
	for(; '0'<=c && c<='9'; c=gc())
		rs=(rs<<1)+(rs<<3)+(c-'0');
	if(neg) rs=-rs;
	return rs;
}
ll get_l(){
	char c=gc(); bool neg=false;
	for(; c<'0'||'9'<c; c=gc())
		if(c=='-') neg=true;
	ll rs=c-'0'; c=gc();
	for(; '0'<=c && c<='9'; c=gc())
		rs=rs*10ll+(c-'0');
	if(neg) rs=-rs;
	return rs;
}
string get_s(){
	char c=gc();
	for(; c<33 || 126<c; c=gc());
	string s=""; s+=c; c=gc();
	for(; 33<=c && c<=126; c=gc())
		s+=c;
	return s;
}
char get_c(){
	char c=gc();
	for(; c<33 || 126<c; c=gc());
	return c;
}
void print_i(int _n){
	bool neg=false; if(_n<0) {neg=true; _n=-_n;}
	if(neg) pc('-');
	int N=_n, rev, count=0;
	rev=N;
	if(N==0) {pc('0'); return;}
	while((rev%10)==0) {count++; rev/=10;}
	rev=0;
	while(N!=0) {rev=(rev<<3)+(rev<<1)+N%10; N/=10;}
	while(rev!=0) {pc(rev%10+'0'); rev/=10;}
	while(count--) pc('0');
}
void print_l(ll _n){
	ll N=_n, rev, count=0;
	rev=N;
	if(N==0) {pc('0'); return;}
	while((rev%10)==0) {count++; rev/=10;}
	rev=0;
	while(N!=0) {rev=rev*10ll+N%10; N/=10;}
	while(rev!=0) {pc(rev%10+'0'); rev/=10;}
	while(count--) pc('0');
}
void print_s(string a){
	for(int i=0; i<a.size(); i++)
		pc(a[i]);
}
#define endline pc('\n');
#define space pc(' ');
/* end fast input/output */

/*   E N D   O F   T E M P L A T E   */

ll dp[3005][3005];
int n, s, a[3005];
int main(){
	n=get_i(); s=get_i();
	for(int i=1; i<=n; i++) a[i]=get_i();
	dp[0][0]=1;
	for(int i=1; i<=n; i++) for(int j=0; j<=s; j++){
		dp[i][j]=dp[i-1][j];
		if(j>=a[i]){
			if(j==a[i]) dp[i][j]=(dp[i][j]+(ll)i*dp[i-1][j-a[i]])%mod;
			else dp[i][j]=(dp[i][j]+dp[i-1][j-a[i]])%mod;
		}
	}
	ll ans=0ll;
	for(int i=1; i<=n; i++) ans=(ans+dp[i][s])%mod;
	print_l(ans); endline return 0;
}