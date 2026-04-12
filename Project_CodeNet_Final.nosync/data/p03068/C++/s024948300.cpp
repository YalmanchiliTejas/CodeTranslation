#include <string>
#include <algorithm>
#include <iostream>
#define OPEN 0
using namespace std;
int main(){
	int N,K;
	string S;
	#if OPEN
		freopen("input.txt","r",stdin);
		//freopen("output.txt","w",stdout);
	#endif
	while(cin>>N>>S>>K){
		char t = S[K-1];
		string out= S;
		int s = out.size();
		for(int i = 0;i<s;i++){
			if(out[i]!=t)out[i] = '*';
		}
		cout<<out<<endl;
	}
	return 0;
}