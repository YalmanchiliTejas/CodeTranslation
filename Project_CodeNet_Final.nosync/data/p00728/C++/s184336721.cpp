#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int n;
	while(cin >> n,n){
		int s[100],min = 1000,max = 0,sum = 0;
		for(int i = 0; i < n; i++){
			cin >> s[i];
			sum += s[i];
			if(s[i] < min){
				min = s[i];
			}
			if(s[i] > max){
				max = s[i];
			}
		}
		sum -= min + max;
		cout << floor(double(sum/(n-2))) << endl;
	}
	return 0;
}