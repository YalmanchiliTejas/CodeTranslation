//Sani buyuk Osman Pasa Plevneden cikmam diyor.
//FatihSultanMehmedHan
//Abdulhamid Han
//Bismillahirrahmanirrahim

#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>

using namespace std;

typedef long long int lo;
typedef pair< int,int > PII;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define fio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define FOR for(int i=1;i<=n;i++)
#define mid ((start+end)/2)
#define ort ((bas+son)/2)

const lo MAX = -1000000000000000000; 
const lo MIN = 1000000000000000000; 
const lo inf = 1000000000; 
const lo KOK = 100000; 
const lo LOG = 30; 
const lo li = 100005; 
const lo mod = 1000000007; 

int n,m,b,a[li],k,flag;
int cev;
string s;
vector<int> v;

int main(void){
	scanf("%d",&n);
	if(n==5 || n==7 || n==3){printf("YES");}
	else printf("NO");
	return 0;
}
