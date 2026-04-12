#include<iostream>
#include<vector>
using namespace std;
int main(){
	int N;
	cin >> N;
	vector<int> H(N);
	for(int i=0; i<N; i++){
		cin >> H[i];
	}
	int count=1;
	for(int i=1; i<N; i++){
		int flag=0;
		for(int j=0; j<i; j++){
			if(H[i]>=H[j])flag++;
		}
		if(flag==i)count++;
	}
	cout << count << endl;
	return 0;
}