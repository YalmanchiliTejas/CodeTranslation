#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	long long a[n];
	for(int i=0; i<n; i++){
		cin >> a[i];
	}
	
	if(n%2==0){
		for(int i=n-1; i>=0; i--){
			if(i%2==1){
				cout << a[i];
				if(i!=n-2){cout<<" ";}
			}
	
		}
		for(int i=0; i<n; i++){
			if(i%2==0){
				cout << a[i];
				if(i!=n-2){cout<<" ";}
			}


		}
	}
	if(n%2==1){
		for(int i=n-1; i>=0; i--){
			if(i%2==0){
				cout << a[i];
				if(i!=n-2){cout<<" ";}				
			}

		}
		for(int i=0; i<n; i++){
			if(i%2==1){
				cout << a[i];
				if(i!=n-2){cout<<" ";}
			}
			
		}
	}
	
	cout<<endl;
	return 0;
}