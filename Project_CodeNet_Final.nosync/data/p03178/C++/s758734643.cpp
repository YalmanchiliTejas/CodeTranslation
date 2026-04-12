#include<bits/stdc++.h>
using namespace std;
#define pfi(a) printf("%d",a);
#define pfl(a) printf("%lld",a);
#define pfin(a) printf("%d\n",a);
#define pfln(a) printf("%lld\n",a);
#define sfi(a) scanf("%d",&a);
#define sfl(a) scanf("%lld",&a);
#define pb push_back
#define f(i,a,b) for(int i=a;i<b;i++)
#define ll long long
const ll M=1e9+7;
const int MAXN=3e5+4;
const int MAXN2=5e4;






int main(){

	string s;
	cin>>s;

	int d;
	cin>>d;

	int len=s.length();

	vector<vector<int>> dp(d,vector<int>(2));

	dp[0][0]=1;




	for(int i=0;i<len;i++){
		vector<vector<int>> dp_new(d,vector<int>(2));
		for(int sum=0;sum<d;sum++){
			for(bool smal:{false,true}){



				for(int digit=0;digit<10;digit++){

					if(digit>(s[i]- '0') && smal==0){
						break;
					}

					dp_new[(sum+digit)%d][smal || (digit<(s[i]-'0'))]+=dp[sum][smal];
					dp_new[(sum+digit)%d][smal || (digit<(s[i]-'0'))]%=M;
				}
			}
		}

		dp=dp_new;
	}


	
	ll ans=(dp[0][0] + dp[0][1])%M;
	ans=(ans-1+M)%M;
	
	pfln(ans)
	
	return 0;	
}