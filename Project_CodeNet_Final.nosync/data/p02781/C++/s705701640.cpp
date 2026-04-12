/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll k;
ll dp[5][2][100000];
vector<ll>v;
ll digit_dp(vector<ll>v,ll cnt,ll tight,ll pos){
	///cout<<cnt<<" "<<tight<<" "<<pos<<endl;
    ll i;
    ll res=0;
    if(pos>=v.size()&&cnt==k)
    return 1;
    else if(pos>=v.size()&&cnt!=k)
    return 0;
    else if(cnt>k)
    return 0;
    if(dp[cnt][tight][pos]!=-1)
    return dp[cnt][tight][pos];
    ll chuto;
    if(tight==1||pos==0)
    chuto=v[pos];
    else
    chuto=9;
    ///cout<<chuto<<endl;
    if(pos==0){
    	for(i=0;i<=chuto;i++){
    		if(i==chuto){
    			if(i!=0)
                res+=(digit_dp(v,cnt+1,1,pos+1));
                else
                res+=(digit_dp(v,cnt,1,pos+1));
			}
			else{
				 if(i!=0)
                 res+=(digit_dp(v,cnt+1,0,pos+1));
                 else
                 res+=(digit_dp(v,cnt,0,pos+1));
			}
		}
		return dp[cnt][tight][pos]=res;
	}
	else{
      for(i=0;i<=chuto;i++){
          if(tight==1&&i==chuto){
              if(i!=0)
              res+=(digit_dp(v,cnt+1,1,pos+1));
              else
              res+=(digit_dp(v,cnt,1,pos+1));
         }
          else{
              if(i!=0)
               res+=(digit_dp(v,cnt+1,0,pos+1));
              else
               res+=(digit_dp(v,cnt,0,pos+1));
          }
     }
     return dp[cnt][tight][pos]=res;
   }
}
int main()
{
    ios_base::sync_with_stdio(false);
    string s;
    ll n,i,j,l;
    for(i=0;i<=4;i++){
        for(j=0;j<=1;j++){
            for(l=0;l<=1000;l++)
            dp[i][j][l]=-1;
        }
    }
    cin>>s>>k;
    ll sz=s.size();
    for(i=0;i<sz;i++)
    v.push_back(s[i]-'0');
    cout<<digit_dp(v,0,0,0);
    return 0;
}
