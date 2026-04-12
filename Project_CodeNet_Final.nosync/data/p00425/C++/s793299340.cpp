#include<iostream>
#include<string>
using namespace std;
int main(){
	int n;
	int me[6];
	int cmp;
	int sum[5];
	int hasi;
	string str;
	sum[0]=1;
	sum[1]=1;
	sum[2]=1;
	sum[3]=1;
	sum[4]=1;
	sum[5]=1;
	for(int i=0;i<10;i++){
		cin >> n;
		if(n==0){
			hasi=i;
			break;
		}
		me[0]=1;
		me[1]=2;
		me[2]=3;
		me[3]=4;
		me[4]=5;
		me[5]=6;
			for(int i0=0;i0<n;i0++){
				cin >> str;
				if(str=="North"){
					cmp=me[0];
					me[0]=me[1];
					me[1]=me[5];
					me[5]=me[4];
					me[4]=cmp;
				}
				else if(str=="East"){
					cmp=me[0];
					me[0]=me[3];
					me[3]=me[5];
					me[5]=me[2];
					me[2]=cmp;
				}
				else if(str=="West"){
					cmp=me[0];
					me[0]=me[2];
					me[2]=me[5];
					me[5]=me[3];
					me[3]=cmp;
				}
				else if(str=="South"){
					cmp=me[0];
					me[0]=me[4];
					me[4]=me[5];
					me[5]=me[1];
					me[1]=cmp;
				}
				else if(str=="Right"){
					cmp=me[1];
					me[1]=me[2];
					me[2]=me[4];
					me[4]=me[3];
					me[3]=cmp;
				}
				else if(str=="Left"){
					cmp=me[1];
					me[1]=me[3];
					me[3]=me[4];
					me[4]=me[2];
					me[2]=cmp;
				}
				sum[i]+=me[0];
			}
			hasi=i;
	}
	for(int i=0;i<hasi;i++){
		cout << sum[i] << endl;
	}
	return 0;
}