#include<bits/stdc++.h>
#include<iomanip>

#define ll long long
#define ar array
 
using namespace std;

int main() {
	
	int n, h[100000],aux=1;
	
	cin >> n;
	
	for(int i=0;i<n;i++){
		cin >> h[i];
	}
	int base=h[0];
	for(int i=1;i<n;i++){
		if(h[i]>=base){
			aux++;
			if(h[i]>base){
				base  = h[i];
			}
		}
	}
	cout << aux << endl;
	
   	return 0;
}