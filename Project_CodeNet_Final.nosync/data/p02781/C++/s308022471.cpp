#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=(a);i<(b);i++)
#define qi queue<int>
#define vi vector<int>
#define ll long long
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define pii pair<int,int>
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define fi first
#define se second
#define prq priority_queue
#define foreach(it,c) for(__typeof((c).begin()) it=c.begin();it!=c.end();it++)
//#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)
using namespace std;
inline ll read(){
	ll x=0;
	int f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-')f=-f;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	return x*f;
}
inline void out(int x){
	if(x>=10)out(x/10);
	putchar(x%10+'0');
}
string s;
int k,n,C[111][22];
int main(){
	//freopen("a.in","r",stdin);
	//freopen("a.out","w",stdout);
	cin>>s>>k;
	n=s.size();
	if(k==1){
		cout<<9*(n-1)+(s[0]-'0');
		return 0;
	}
	C[0][0]=1;
	C[1][0]=C[1][1]=1;
	fo(i,2,102) fo(j,0,11)C[i][j]=C[i-1][j-1]+C[i-1][j];
	string t="";
	t+=s[0];
	int ans=0;
	fo(i,1,n) fo(x,1,10){
		string t1=t;
		fo(j,0,i-1)t+='0';
		t+=(x+'0');
		if(k>2){
			fo(j,i+1,n) fo(y,1,10){
				string t2=t;
				fo(r,0,j-i-1)t+='0';
				t+=(y+'0');
				while(t.size()<n)t+='0';
				if(t<=s)ans++;
				t=t2;
			}
		}else{
			while(t.size()<n)t+='0';
			if(t<=s)ans++;
		}
		t=t1;
	}
	ans+=(s[0]-'1')*C[n-1][k-1]*pow(9,k-1)+C[n-1][k]*pow(9,k);
	cout<<ans<<endl;
	return 0;
}
