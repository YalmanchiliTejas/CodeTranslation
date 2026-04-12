#include<iostream>
#include<string>
#include<vector>

long long calcComb(long long n, long long r){
	long long numer=1;
	long long denom=1;

	for(long long i=0; i<r; i++)
		numer*= (n-i);

	for(long long i=0; i<r; i++)
		denom*= (r-i);

	return numer/denom;
}

int main(){
	std::string s;
	long long n;

	long long ans= 0;

	std::cin>>s;
	std::cin>>n;

	std::vector<long long> pow9(n+1, 1);
	for(long long i=0; i<n; i++) 
		pow9[i+1]= pow9[i]*9;

	long long digit= s.size();
	long long fixdeg= 0;

	for(long long i=0; i<digit; i++){
		long long top= s[i]-'0';

		if(top>0){
			ans+= pow9[n-fixdeg] * calcComb(digit-i-1, n-fixdeg);
			ans+= pow9[n-fixdeg-1] * (top-1) * calcComb(digit-i-1, n-fixdeg-1);
			fixdeg++;
		}

		if(fixdeg>= n){
			ans++;
			break;
		}
	}

	std::cout<<ans<<std::endl;

	return 0;
}