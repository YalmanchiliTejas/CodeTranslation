#include<iostream>

using namespace std;







int main(void){
	long X,Y,Z;
	cin >> X ;
	cin >> Y;
	cin >> Z;
	
	int ans = 0;
	
	for(int i = 0; (i*(Y+Z)+Z) <= X; i++){
		ans = i;
	}
	
	cout << ans << endl;
	
	
	return 0;
}