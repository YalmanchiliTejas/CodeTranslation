#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	int a, b, tmp, tmp2;
	char w;
	while(1){
		cin >> a >> b;
		
		if(a == 0 && b == 0){
			break;
		}
		
		w = 'A';
		tmp = a + b;
		tmp2 = 0;
		for(int i = 1; i <= 4; i++){
			cin >> a >> b;
			if(tmp < (a+b)){
				tmp = a + b;
				tmp2 = i;
			}
		}
		
		cout << (char)(w+tmp2) << " " << tmp << endl;
	}
	
	return 0;
}