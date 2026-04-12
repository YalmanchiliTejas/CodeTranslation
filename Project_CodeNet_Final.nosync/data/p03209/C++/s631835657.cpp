#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
using namespace std;
const int INF=1000000007;

int main (void){
    long long int n,x,i,ps=0;
    cin >> n >> x;
    for(i=n;i>=0;i--){
    	if(x==0) break;
    	if(i==0){
    		ps++;
    		break;
    	}
    	if(x==pow(2,i+2)-3) x=x-1;
    	if(x>=pow(2,i+1)-1){
    		ps+=pow(2,i);
    		x=x-pow(2,i+1)+1;
    	} else {
    		x=x-1;
    	}
    }
    cout << ps << endl;
    return 0;
}