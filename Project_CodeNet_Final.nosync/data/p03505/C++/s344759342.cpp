#include <iostream>
typedef long long LL;
using namespace std;
int main(int argc, char* argv[])
{
	LL K,A,B;
	cin>>K>>A>>B;
	if (K<=A){
		cout<<1<<endl;
		return 0;
	}
	if (A<=B){
		cout<<-1<<endl;
		return 0;
	}
	LL AB=A-B;
	LL x=(K-A)/AB;
	LL y=K%AB;
	LL z=x*AB;
	LL aw=2*x;
	while (z<K){
		aw++;
		z+=A;
		if (z>=K){
			break;
		}
		z-=B;
		aw++;
	}
	cout<<aw<<endl;
	return 0;
}