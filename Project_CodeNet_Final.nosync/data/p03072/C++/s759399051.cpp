#include <iostream>
using namespace std;
int main() {
	cin.tie(0);
   	ios::sync_with_stdio(false);

	int N;
	cin >> N;
  	int array[N];
	for(int i=0;i<N;i++){
    	cin >> array[i];
    }
  
  	int y=1;
 	for(int i=1;i<N;i++){
      	int flag=0;
    	for(int j=0;j<i;j++){
        	if (array[i] < array[j]){
            	flag = 1;
              	break;
            }
        }
        if (flag == 0){
        	y++;
        }
    } 
  	
    cout << y << "\n";
}