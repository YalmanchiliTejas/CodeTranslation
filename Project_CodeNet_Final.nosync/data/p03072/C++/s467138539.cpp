#include <bits/stdc++.h>
using namespace std;



int main(){
	int n;
	cin>>n;
	int a[n];
	
	for(int i= 0; i < n; i++){
		cin>>a[i];
	}
	bool encontro = false;
	int cont = 0;
	
	for(int i = 0; i < n; i++){
		encontro == false;
		for(int j = 0; j < i && encontro == false; j++){
			if(a[i] < a[j]){
				encontro = true;
			}
	    }
	    if(encontro == false){
	    	cont++;
		}
	    encontro = false;
	}
	
	cout << cont;
	return 0;
}