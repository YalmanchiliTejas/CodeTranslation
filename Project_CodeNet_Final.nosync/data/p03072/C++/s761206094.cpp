#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;
	cin>>N;
	vector<int>H(N);
	for(int i=0;i<N;i++){
		cin>>H[i];
	}
	int total=1,hei=H[0];	
	for(int j=1;j<N;j++){
		if(H[j]>=hei){
			total++;
			hei=H[j];
		}
	}
	cout<<total<<endl;
	return 0;
}
