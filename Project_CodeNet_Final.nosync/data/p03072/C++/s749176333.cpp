#include <iostream>
using namespace std;
int main (){
	int n;
	cin >> n;
	int a[n];
	int max =0;
	int count =0;
	for(int i=0; i< n; i++){
		cin >> a[i];
		if(max <= a[i]){
			count ++;
			max =a[i];
		}
	}
	cout << count << endl;
}
