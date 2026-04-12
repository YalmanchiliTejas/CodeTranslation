#include<iostream>
using namespace std;
 
int main(){
    int n,i;

    while(1){
        int point[100]={0,};
        int min = 1000;
        int max = 0;
		long total = 0;
        cin >> n;
        if(!n) break;
        for(i=0;i<n;i++){
            cin >> point[i];
            if(point[i] > max) max = point[i];
            if(point[i] < min) min = point[i];
			total += point[i];
        }
        cout << (total-max-min)/(n-2) << "\n";
    }

}