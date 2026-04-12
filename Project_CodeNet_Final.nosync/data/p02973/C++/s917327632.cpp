//Sani buyuk Osman Pasa Plevneden cikmam diyor.
//FatihSultanMehmedHan
//Abdulhamid Han
//Bismillahirrahmanirrahim
//█▀█─█──█──█▀█─█─█
//█▄█─█──█──█▄█─█▄█
//█─█─█▄─█▄─█─█─█─█

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>

using namespace std;

typedef long long lo;
typedef pair< int,int > PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR for(lo i=1;i<=n;i++)
#define mid ((start+end)/2)
#define ort ((bas+son)/2)

const lo MAX = -1000000000000000000;
const lo MIN = 1000000000000000000;
const lo inf = 1000000000;
const lo KOK = 100000;
const lo LOG = 30;
const lo li = 500005;
const lo mod = 1000000007;

lo n,m,b[li],a[li],k,flag,t;
lo cev;
string s;
multiset<lo> st;
vector<lo> v;

int main(void){
	scanf("%lld",&n);
	FOR{
		scanf("%lld",&a[i]);
	}
	b[n]=a[1];
	int yer=n;
	for(lo i=2;i<=n;i++){
		if(a[i]<=b[yer]){yer--;b[yer]=a[i];continue;}
		lo bas=yer;
		lo son=n;
		while(bas<=son){
			if(b[ort]<a[i])bas=ort+1;
			else son=ort-1;
		}
		b[son]=a[i];
	}
	printf("%lld\n",n-yer+1);
	return 0;
}
