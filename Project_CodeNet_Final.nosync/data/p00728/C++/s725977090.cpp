#include<iostream>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>
#include<iomanip>
#include<sstream>
#include<vector>
#include<stack>
#include<math.h>
#include<queue>
#include<complex>
#include<random>
#include<ctime>
#include<set>
using namespace std;


const long long int mod=1000000007;
const long long int INF=99999999999999999;



int main() {
	cout << fixed << setprecision(18);
	long long int n,x[120]={},mymin=INF,mymax=-INF,sum=0;
	cin>>n;
	while(n!=0){
		mymin=INF;mymax=-INF,sum=0;
		for(int i=0;i<n;i++){
			cin>>x[i];
			mymin=min(mymin,x[i]);
			mymax=max(mymax,x[i]);
			sum+=x[i];
		}
		cout<<(sum-mymax-mymin)/(n-2)<<endl;
		cin>>n;
	}
} 

