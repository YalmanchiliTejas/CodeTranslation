#include <iostream>
using namespace std;
int main(void){
	int H,W,cnt=0;
	char c;
	cin>>H>>W;
	while(cin>>c)cnt+=c=='#';
	cout<<(cnt==H+W-1 ? "Possible" : "Impossible")<<endl;
	return 0;
}
