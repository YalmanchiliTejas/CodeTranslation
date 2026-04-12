#include <iostream>
#include <string>
using namespace std;
int main(int argc, char* argv[])
{
	int N,K;
	string S;
	cin>>N;
	cin>>S;
	cin>>K;
	int i;
	char ch=S[K-1];
	for (i=0;i<S.size();i++){
		if (S[i]!=ch){
			S[i]='*';
		}
	}
	cout<<S<<endl;
	return 0;
}