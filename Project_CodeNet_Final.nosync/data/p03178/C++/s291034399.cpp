#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
const int sz=1e5 + 5;

string k;
int d,n;

void add_self(int& a,int b){
	a+=b;
	if(a>=mod){
		a-=mod;
	}
}

int main()
{  
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>k>>d;
    n=k.length();
    vector<vector<int>> dp(d,vector<int>(2));
    dp[0][0]=1;
    
    for(int digit=0;digit<n;digit++){
    	vector<vector<int>> new_dp(d,vector<int>(2));
    	for(int j=0;j<d;j++){
    		for(int already_small: {false,true}){
    	        for(int i=0;i<10;i++){
    	        	
    				if(i > k[digit]-'0' && !already_small){
    					break;
					}
					add_self(new_dp[(j+i)%d][already_small || (i<k[digit]-'0')],
					dp[j][already_small]);
				}
			}
		}
		dp=new_dp;
	}
	int answer=(dp[0][0]+dp[0][1])%mod;
	answer-=1;
	if(answer<0)answer+=mod;
	cout<<answer<<"\n";
   
}

