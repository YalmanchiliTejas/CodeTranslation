#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<string>

#define rep(i,p) for(long long int i=0;i<p;i++)
#define reep(i,p) for(long long int i=1;i<=p;i++)
#define ll long long

using namespace std;

int main(){

ll int N;
cin >> N;
ll int sum=0;
ll int M;
M=1000000007;
vector<ll int> A(N);
rep(i,N){
	cin >> A[i];
        sum=(sum+A[i])%M;
}
ll int ans=0;
ll int syo;
rep(i,N-1){
          sum = sum-A[i]%M;
	  if (sum<0) sum+=M;
	  ans = (ans + (sum*A[i])%M)%M;
//cout << ans << endl;
}
cout << ans;

	  









	return 0;

}

