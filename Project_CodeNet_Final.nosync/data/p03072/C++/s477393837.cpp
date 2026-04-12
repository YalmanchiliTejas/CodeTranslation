#include<bits/stdc++.h>
#include<iomanip>

#define ll long long
#define ar array
 
using namespace std;

int main() {

    int a, b, temp = 0, i = 0;
    vector <int> vet;
    
    cin >> a;
	
	while(a--){
		cin >> b;
		
		if(temp <= b){
			temp = b;
			i++;
		}
	}
	
	cout << i << endl;

    return 0;
}