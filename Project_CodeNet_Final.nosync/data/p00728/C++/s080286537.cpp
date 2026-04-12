#include<iostream>
using namespace std;
 
int main(){
    int n,i;
    while(cin >> n,n){
        //int point[100]={0,};
		int p;
        int min = 1000;
        int max = 0;
		int total = 0;
        for(int i=0;i<n;i++){
            //cin >> point[i];
			cin >> p;
            //if(point[i] > max) max = point[i];
			if(p > max) max = p;
            //if(point[i] < min) min = point[i];
			//total += point[i];
			if(p < min) min = p;
			total += p;
        }
        cout << (total-max-min)/(n-2) << "\n";
    }

}