#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char* argv[])
{
	int N,i,j;
	cin>>N;
	vector<int> H(N);
	for (i=0;i<N;i++){
		cin>>H[i];
	}
	int ans=1;
	for (i=1;i<N;i++){
		bool OK=true;
		for (j=0;j<i;j++){
			if (H[j]>H[i]){
				OK=false;
				break;
			}
		}
		if (OK){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}