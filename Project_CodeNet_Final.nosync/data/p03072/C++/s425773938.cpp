#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	int vec[n];
	for(int i=0; i<n; i++)
		cin >> vec[i];
	int max=vec[0], count=1;
	for(int i=1; i<n; i++){
		if(vec[i]==max)
			count++;
		else if(vec[i]>max){
			max=vec[i];
			count++;
		}
	}
	cout << count << endl;

}