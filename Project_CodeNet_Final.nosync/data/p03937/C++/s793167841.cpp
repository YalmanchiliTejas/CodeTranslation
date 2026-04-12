#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(int argc, char* argv[])
{
	int H,W;
	cin>>H>>W;
	vector<string> A(H);
	int i=0;
	int n=0;
	for (i=0;i<H;i++){
		cin>>A[i];
		int j=0;
		while (A[i][j]!='\0'){
			if (A[i][j]=='#'){
				n++;
			}
			j++;
		}
	}
	if (n==H+W-1){
		cout<<"Possible"<<endl;
		return 0;
	}else{
		cout<<"Impossible"<<endl;
		return 0;
	}
	return 0;
}