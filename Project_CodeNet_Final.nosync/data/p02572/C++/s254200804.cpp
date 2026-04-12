#include <iostream>
#include <vector>
using namespace std;
typedef long long LL;
int main(int argc, char* argv[])
{
	const LL MOD=1000000000+7;
	int N,i;
	cin>>N;
	vector<LL> A(N);
	LL hj=0;
	for (i=0;i<N;i++){
		cin>>A[i];
		hj+=A[i];
		hj%=MOD;
	}
	LL Sum=0;
	for (i=0;i<N-1;i++){
		hj-=A[i];
		if (hj<0){
			hj+=MOD;
		}
		LL B=A[i]*hj;
		B%=MOD;
		Sum+=B;
		Sum%=MOD;
	}
	cout<<Sum<<endl;
	return 0;
}