#include <iostream>
#include <cstring>
#define MOD 1000000007
using namespace std;

int kat, n, dp[10010][102];
char arr[10010];


long long int recursive(int konum, int kalan){
	if(konum==n&&kalan==0)return 1;
	if(konum==n)return 0;
	if(dp[konum][kalan]!=-1)return dp[konum][kalan];
	long long int cvp=0;
	for(int i=0;i<10;i++){
		cvp=(cvp+recursive(konum+1, (kalan+i)%kat))%MOD;
	}

	dp[konum][kalan]=cvp;
	return cvp;

}

int kucuk(){
	long long int cvp=0, kalan=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<(arr[i]-'0');j++){
			cvp=(cvp+recursive(i+1, (j+kalan)%kat))%MOD;
		}
		kalan=(arr[i]-'0'+kalan)%kat;
	}
	if(!kalan)cvp=(cvp+1)%MOD;
	return cvp;
}

int main(void){
	cin>>arr;
	cin>>kat;
	memset(dp, -1, sizeof(dp));
	for(int i=0;arr[i];i++)n++;
	cout<<(kucuk()-1+MOD)%MOD;
	return 0;
}
