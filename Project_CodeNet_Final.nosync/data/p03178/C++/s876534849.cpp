#include<bits/stdc++.h>
using namespace std; 
#define ll long long  

#define vll vector<long long> 
#define pii pair<int,int> 
#define vpii vector<pair<int,int>> 
#define pll  pair<long long ,long long > 
#define  pb  push_back
#define fi  first 
#define sec second  
#define SORT(a) sort(a.begin(),a.end()) 
#define m_p make_pair
#define all(x)   (x.begin(),x.end()) 
#define sz(v)     ((int)(v.size()))
typedef vector<int> vi ;
const int nax=10123;
const int MOD=1e9 +7 ; 
int main(){	
	char k[nax]; 
	scanf("%s", &k); 
	int d; 
	cin>>d; 
	int n =strlen(k); 
	vector<vector<int>> dp(d,vector<int>(2));
	dp[0][0]=1; 
	for(int i=0;i<n;i++)
	{
		vector<vector<int>> new_dp(d,vector<int>(2)); 

		for(int sum=0;sum<d;sum++)
		{
			for(bool sm_already:{false,true})
			{	for(int digit=0;digit<=9;digit++)
				{
					if(digit>k[i]-'0' && !sm_already) break; 

					new_dp[(sum+digit)%d][sm_already || digit<k[i]-'0']=(new_dp[(sum+digit)%d][sm_already || digit<k[i]-'0']+dp[sum][sm_already] ) %MOD;
				}
	        }	
		}


		dp=new_dp  ;
	}

	int answer= (dp[0][false]+dp[0][true])%MOD; 
	answer--; 
	if(answer==-1 ) answer=MOD-1; 

	cout<<answer<<endl;
	return 0; 
}