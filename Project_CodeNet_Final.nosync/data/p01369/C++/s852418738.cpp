#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	string S,L="qwertasdfgzxcvb";
	while(cin>>S,S[0]!='#') {
		vector<bool> v;
		for(int i=0;i<S.size();i++) {
			bool b=0;
			for(int j=0;j<L.size();j++) {
				if(S[i]==L[j]) b=1;
			}
			v.push_back(b);
		}
		int sum=0;
		for(int i=1;i<v.size();i++) {
			if(v[i-1]!=v[i]) sum++;
		}
		cout<<sum<<endl;
	}
}