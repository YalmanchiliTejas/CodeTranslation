#include <iostream>

using namespace std;

int main(){
	int n,i;
	cin >> n;
	int a[n];
	for(i=0;i<n;i++){
		cin >> a[i];
	}
	
	if(n%2==0){
		for(i=0;i<n;i+=2){
			cout << a[n-1-i] << " ";
		}
		for(i=0;i<n;i+=2){
			cout << a[i] << " " ;
		}
		cout << endl;
	}else{
		for(i=0;i<n;i+=2){
			cout << a[n-1-i] << " ";
		}
		for(i=1;i<n;i+=2){
			cout << a[i] << " ";
		}
		cout << endl;
	}
}
			