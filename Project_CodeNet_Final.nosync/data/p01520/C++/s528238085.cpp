#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main(){
	int n,t,e,x[1001],k;
	
	cin >> n >> t >> e ;
	for(int i=1;i<=n;i++){
		cin >> x[i];
	}
	for(int i=1;i<=n;i++){
		k=x[i];
		while(1){
			if(t-e>k){
				k+=x[i];
			}
			else if(t+e<k){
				break;
			}
			else{
				cout << i <<"\n";
				return 0;
			}
		}
	}
	cout << "-1\n";
return 0;
}