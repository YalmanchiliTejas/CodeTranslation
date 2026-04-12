#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	int total;
	int me[6];
	int b;
	string s;
	cin >> n;
	while(n){
		total=1;
		me[0]=1,me[1]=2,me[2]=3,me[3]=5,me[4]=4;me[5]=6;
		for(int i=0;i<n;i++){
			cin >> s;
			if(s=="North"){
				b=me[0];
				me[0]=me[1];
				me[1]=me[5];
				me[5]=me[3];
				me[3]=b;
			}else if(s=="East"){
				b=me[0];
				me[0]=me[4];
				me[4]=me[5];
				me[5]=me[2];
				me[2]=b;
			}else if(s=="West"){
				b=me[0];
				me[0]=me[2];
				me[2]=me[5];
				me[5]=me[4];
				me[4]=b;
			}else if(s=="South"){
				b=me[0];
				me[0]=me[3];
				me[3]=me[5];
				me[5]=me[1];
				me[1]=b;
			}else if(s=="Right"){
				b=me[1];
				me[1]=me[2];
				me[2]=me[3];
				me[3]=me[4];
				me[4]=b;
			}else if(s=="Left"){
				b=me[1];
				me[1]=me[4];
				me[4]=me[3];
				me[3]=me[2];
				me[2]=b;
			}
			total+=me[0];
		}
		cout << total << endl;
		cin >> n;
	}
	return 0;
}