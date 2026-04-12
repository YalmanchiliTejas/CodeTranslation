#include <bits/stdc++.h>
using namespace std;

int main(){
	int N;
	cin >> N;
	
	vector<int> H(N);
	for(int i=0;i<N;i++){
		cin >> H.at(i);
	}

	vector<int> I((N+1)*(N+1));
	int count=0;
	
	for(int i=0;i<N;i++){
		for(int j=0;j<=i;j++){
			I.at(i*N+j)=H.at(i)-H.at(j);
			if(I.at(i*N+j)<0){
				count++;
				break;
			}
		}
		
	}
	
	cout << N-count << endl;

}