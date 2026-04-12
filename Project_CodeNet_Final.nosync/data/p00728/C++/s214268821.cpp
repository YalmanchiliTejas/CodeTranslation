#include<iostream>
using namespace std;
 
int main(){
    int n,i;
	//cout<< "1000*100 = " << 1000*100 << "\n" << "int_max = " << INT_MAX << "\n";
    while(cin >> n,n){
        int point[100]={0,};
        int min = 1000;
        int max = 0;
		int total = 0;
        //if(!n) break;
        for(i=0;i<n;i++){
            cin >> point[i];
            if(point[i] > max) max = point[i];
            if(point[i] < min) min = point[i];
			total += point[i];
        }
        cout << (total-max-min)/(n-2) << "\n";
    }

}