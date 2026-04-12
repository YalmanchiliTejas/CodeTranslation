#include <iostream>
using namespace std;

void edit(int list[], int i);

int main() {
	// your code goes here
	int n, col, count;
	int *list;
	
	while(cin >> n, n != 0){
		count = 0;
		list = new int[n];
		
		for(int i=0; i<n; i++){
			cin >> col;
			if(i%2 == 0){
				list[i] = col;
			}
			else{
				if(list[i-1] == col) list[i] = col;
				else{
					list[i] = col;
					edit(list, i);
				}
			}
		}
		
		for(int i=0; i<n; i++){
			if(list[i] == 0) count++;
		}
		cout << count << endl;
		
		delete [] list;
	}
	return 0;
}

void edit(int list[], int i)
{
	int col = list[i];
	for(int j=1; j<=i; j++){
		if(list[i-j] != col) list[i-j] = col;
		else break;
	}
}