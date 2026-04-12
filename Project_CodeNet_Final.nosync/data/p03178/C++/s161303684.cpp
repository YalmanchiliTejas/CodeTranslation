#include<iostream>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<sstream>
 
using namespace std;
		
	long long dp[10099][121]; // KONJU NEMORAS SUMU NEGO %moD
	#define MOD 1000000007
	int d; 
	
	long long suma = 0;
	string A; 
	
	void rek(int idx, int pass){
		
		//cout << "kurac" ;
		
		if(idx == A.size()){
		//	cout << pass << " " <<"KRAJ";
			if(pass%d==0)suma++;
			return;
		}
		
		for(int i = 0; i < A[idx] - '0'; i++){
			suma += dp[A.size() - idx - 1][((d - i - pass)%d + 5*d)%d];
			suma %= MOD;
		//	suma = (suma + dp[A.size() - idx - 1][((d - i - pass)%d + d)%d])%MOD;
		//	cout << A.size() - idx - 1 << " " << ((d- i - pass)%d + d)%d << endl;
		//	cout << dp[19][2] << endl;
		//	cout << suma << " " << A.size() - idx - 1 << " " << dp[A.size() - idx - 1][((d - i - pass)%d + 5*d)%d] << " " << ((d - i - pass)%d + 5*d)%d << endl;
		} 
		
		//cout << suma <<  " " << idx << endl; system("pause");
		pass += A[idx] - '0';
		pass%=d;
		
		rek(idx+1,pass);
		
		return;
		
	}
 
int main(){
 
	cin >> A;
	cin >> d;
	
	//cout << d << endl;
	
	//cout << (-1)%222 << endl;
	
	dp[0][0] = 1;
	
	for(int i = 0; i < 10009; i++){
		
		for(int j = 0; j < 111; j++){
			
			dp[i][j]%=MOD;
			
	//		cout << dp[i][j] << " ";
			for(int k = 0; k < 10; k++){
				
				dp[i+1][(j+k)%d] += dp[i][j];
				dp[i+1][(j+k)%d]%=MOD;
				
			}
		}
	//	cout <<endl;
		
	}
	
	//system("pause");
	//suma += dp[B.size()-1][0];
	//cout << suma << endl;
	
	rek(0,0);
	cout <<((suma - 1)%MOD + MOD)%MOD;
	
 
 
 
 
	return 0;
}