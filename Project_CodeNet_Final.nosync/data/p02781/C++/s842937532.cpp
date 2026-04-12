#include<iostream> 
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<sstream>
#include<iomanip>
using namespace std;

#define sf scanf
#define pf printf
#define pfn printf("\n");
#define pfk printf(" ");
#define pf0 printf("0");
#define pf1 printf("1");
#define ll long long
#define sfd(n) scanf("%d",&n);
#define sfdd(n,m) scanf("%d%d",&n,&m);
#define sfld(n) scanf("%lld",&n);
#define sfldd(n,m) scanf("%lld%lld",&n,&m);
#define sflf(n) scanf("%lf",&n);
#define sflff(n,m) scanf("%lf%lf",&n,&m);
#define sfc(n) scanf("%c",n);
#define sfcc(n,m) scanf("%c%c",n,m);
#define sfs(n) scanf("%s",n);
#define sfss(n,m) scanf("%s%s",n,m);
#define pfd(n) printf("%d",n);
#define pfld(n) printf("%lld",n);
#define pflf(n) printf("%lf",n);
#define pfc(n) printf("%c",n);
#define pfs(n) printf("%s",n);

#define csh(a,n) memset(a,n,sizeof(a));

int main(){
	char arr[1010];
	ll k;
	cin>>arr;
	cin>>k;
	ll n=strlen(arr);
	if(k==1){
		cout<<(n-1)*9+arr[0]-'0';
	}
	else if(k==2){
		ll sum=0;
		for(ll i=1;i<n;i++){
			if(arr[i]!='0'){
				sum+=(arr[i]-'0'+9*(n-i-1));
				break;
			}
		}
		sum+=(arr[0]-'1')*9*(n-1);
		for(ll i=1;i<n-1;i++){
			for(ll j=i+1;j<n;j++){
				sum+=9*9;
			}
		}
		cout<<sum<<endl;
	}
	else{
		ll sum=0;
		for(ll i=1;i<n;i++){
			if(arr[i]!='0'){
				for(ll j=i+1;j<n;j++){
					if(arr[j]!='0'){
						sum+=(arr[j]-'0'+9*(n-j-1));
						break;
					}
				}
				sum+=(arr[i]-'1')*9*(n-i-1);
				for(ll j=i+1;j<n-1;j++){
					for(ll z=j+1;z<n;z++){
						sum+=9*9;
					}
				}
				break;
			}
		}
		for(ll i=1;i<n-1;i++){
			for(ll j=i+1;j<n;j++){
				sum+=(arr[0]-'1')*9*9;
			}
		}
		for(ll i=1;i<n-2;i++){
			for(ll j=i+1;j<n-1;j++){
				for(ll z=j+1;z<n;z++){
					sum+=9*9*9;
				}
			}
		}
		cout<<sum<<endl;
	}
}