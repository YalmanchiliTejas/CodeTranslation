#include<iostream>

using namespace std;

int main() {
	const int M=1000000007;
	int n;
	long long x, s1=0, s2=0;
	cin>>n;
	while(n--){
		cin>>x;
		s2+=s1*x;
		s2%=M;
		s1+=x;
		s1%=M;
	}
	cout<<s2<<endl;
	return 0;
}