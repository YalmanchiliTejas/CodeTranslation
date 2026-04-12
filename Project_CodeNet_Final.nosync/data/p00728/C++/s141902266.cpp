#include<iostream>
using namespace std;
int main(){
    register int n,i;
    while(cin >> n,n){
		register int p;
        register int min = 1000;
        register int max = 0;
		register int total = 0;
		for(int i=0;i<n;i++){
			cin >> p;
			if(p > max) max = p;
			if(p < min) min = p;
			total += p;
        }
        cout << (total-max-min)/(n-2) << "\n";
    }
}