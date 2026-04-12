
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main(){
	/*input*/
	int n;
	cin >> n;
	int h[20];
    for(int i = 0; i < n; i++){
    	cin >> h[i];
    }

    /*calc*/
    int  ans = 1;
    int max = h[0];
    for(int i = 1; i < n; i++){
    	if(max <= h[i]){
    		ans += 1;
    		max = h[i];
    	}
    }
    /*output*/
	   	cout<< ans <<endl;
    return 0;
}
