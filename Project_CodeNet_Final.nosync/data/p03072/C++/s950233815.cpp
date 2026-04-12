#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	int ma,H,count;
	count=1;
	cin >>H;
	ma=H;
	for(int i=1;i<N;i++){
		cin >>H;
		if(H>=ma){
			ma=H;
			count++;
		}
	}
	cout<<count<<endl;
}