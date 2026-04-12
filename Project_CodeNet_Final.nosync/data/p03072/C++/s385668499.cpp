#include <iostream>

using namespace std;

int n, sol;

int main(){
cin >> n;
int maxi = 0;
for(int i = 0 ; i < n ; ++i){
	int x;
	cin >> x;
	if(x >= maxi){
		sol++;
	}
	maxi = max(x, maxi);
}
cout << sol << endl;

return 0;
}

