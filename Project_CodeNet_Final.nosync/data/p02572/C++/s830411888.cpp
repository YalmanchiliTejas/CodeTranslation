#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
namespace mp = boost::multiprecision;
// 任意長整数型
using Bint = mp::cpp_int;
// 仮数部が1024ビットの浮動小数点数型(TLEしたら小さくする)
using Real = mp::number<mp::cpp_dec_float<1024>>;

int main()
{
	int N;
	int mod=1000000007;
	cin >> N ;
	vector<int> A(N);
	vector<long long> B(N+1,0);
	for(int i=0;i<N;i++)
	{
		cin >> A.at(i);
		B.at(i+1)=B.at(i)+A.at(i);
	}
	
	long ans=0;
	
	for(int i=0;i<N;i++)
	{
		long long sum = (B.at(N)-B.at(i+1))%mod;
		ans+=A.at(i)*sum;
		ans%=mod;
	}
	
	cout << ans << endl;
}