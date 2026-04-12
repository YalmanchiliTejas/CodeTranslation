#include <iostream>

using namespace std;
int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	cin >> a;
	int array[a-1];
	for(int i = 0; i < a;i++ ){
		cin >> array[i];
	}
	for(int i = 0;i < a;i++){
		if(array[i] >= array[b]){
			c += 1;
			b = i;
	}
	}
	cout << c << endl;
}