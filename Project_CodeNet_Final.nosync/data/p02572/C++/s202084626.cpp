#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <stack>
#include <string>
#include <cstring>
#include <numeric>
#include <iomanip>
#include <fstream>
using namespace std;
long long mod=1e9+7;
template<class T>struct mow{
	T pow(T x,T n){
		T ret=1;
		if(n>0){
			ret=pow(x,n/2);
			if(n%2==0){
				(ret=(ret*ret))%=mod;
			}else{
				(ret=((ret*ret)%mod)*x)%=mod;
			}
		}
		return ret;
	}
	T inv(T n){
		return pow(n,mod-2);
	}
};
int main(){
	int n;
	long long a[200000];
	cin>>n;
	long long s=0;
	long long ss=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		(s+=a[i])%=mod;
		(ss+=a[i]*a[i])%=mod;
	}
	(s*=s)%=mod;
	s+=mod;
	s-=ss;
	s%=mod;
	mow<long long> nii;
	s*=nii.inv(2);
	s%=mod;
	cout<<s<<endl;
	return 0;
}
