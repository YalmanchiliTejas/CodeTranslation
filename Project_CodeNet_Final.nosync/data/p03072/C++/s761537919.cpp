#include <iostream>
using namespace std;

int main()
{
	int N,i;
	cin >>N;
	int H[N],ans = 1,maxh;
	for(i=0;i<N;i++){
		cin>> H[i];
	}
	maxh = H[0];
	for(i=1;i<N;i++){
		if(maxh<=H[i]){
			ans +=1;
			maxh =H[i];
		}
	}
	cout <<ans;
	return 0;
}
