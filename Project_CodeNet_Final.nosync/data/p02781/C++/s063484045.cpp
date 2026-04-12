#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[101][4][2];

int main() {
	string N;
	cin>>N;
	ll K;
	cin>>K;
	dp[0][0][0]=1;
	for(ll i=0;i<N.size();i++){
      for(ll k=0;k<=3;k++){
        ll temp=N[i]-'0';//現在の桁              
        for(ll j=0;j<10;j++){
				if(j==0){
					if(j==temp){
                      //次の桁も現在の桁も0なのでkは変わらない
						dp[i+1][k][0]+=dp[i][k][0];
                    }
					else if(j<temp){
						dp[i+1][k][1]+=dp[i][k][0];
					}
					dp[i+1][k][1]+=dp[i][k][1];
				}
              
				else{
                  if(k==3) continue;
					if(j==temp){
						dp[i+1][k+1][0]+=dp[i][k][0];
					}
					else if(j<temp){
						dp[i+1][k+1][1]+=dp[i][k][0];
					}
					dp[i+1][k+1][1]+=dp[i][k][1];					
				}
              
			}
		}
	}
	cout << dp[N.size()][K][0]+dp[N.size()][K][1];
	return 0;
}
