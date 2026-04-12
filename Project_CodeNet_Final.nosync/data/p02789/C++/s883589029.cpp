#include<bits/stdc++.h>
#include<set>
#include<bitset>
#define rep(i,a,b)  for(i=a;i<b;i++)
#define itrep(at)	for(auto it=at.begin();it!=at.end();it++)
#define sort(v)	sort(v.begin(),v.end());
#define lli long long int
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define vll vector<long long int>
#define vs vector<string>
#define vb vector<bool>
#define vc vector<char>
#define vvll vector<vector<long long int> >
#define sll set<long long int>
#define mll map<long long int,long long int>
#define sllit set<long long int>::iterator
#define pll pair<long long int,long long int>
#define vpll vector<pair<long long int,long long int> >
#define db double
#define M 1000000007
#define pi 3.1415926535897932384626433832795028841971
using namespace std;
lli min(lli a,lli b){return a<b?a:b;}
lli min(lli a,lli b,lli c){a=min(a,b);a=min(a,c);return a;}
lli max(lli a,lli b){return a>b?a:b;}
lli max(lli a,lli b,lli c){a=max(a,b);a=max(a,c);return a;}
lli power(lli a,lli b){lli res=1;while(b){if(b&1) res=res*a;a=a*a;b>>=1;}return res;}
lli mpower(lli a,lli b,lli m){lli res=1;a=a%m;while(b){if(b&1){res=(res*a)%m;}a=((a%m)*(a%m))%m;b>>=1;}return res;}
lli gcd(lli a,lli b){if(b==0) return a;if(a==0) return b;if(a>=b) return gcd(b,a%b);else return gcd(a,b%a);}
lli lcm(lli a,lli b){lli p=a*b;return p/gcd(a,b);}
/*
vector<bool> is_prime(10000005,true);
void sieve()
{
	long long int i,j;
	is_prime[0]=false;
	is_prime[1]=false;
	for(i=2;i<=10000004;i++){
		if(is_prime[i]){
			for(j=i*i;j<=10000004;j+=i){
				is_prime[j]=false;
			}
		}
	}
}
*/





int main()
{
	char ch,ch1,ch2;
	string s1,s2,s3;
    lli i,j,k,a,b,c,n,m,sum=0,ans=0,temp;
    cin >> n >> m;
    if(m==n)	cout << "Yes" << endl;
    else cout << "No" << endl;
	
	
    
    
    return 0;
}





















/* UJJWAL KESHRI */