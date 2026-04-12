
// 入力
// N
// yyyy-mm-dd string int1 int2
// yyyy-mm-dd string int1 int2
// yyyy-mm-dd string int1 int2
// yyyy-mm-dd string int1 int2


#include <iostream>
#include <string>
using namespace std;

struct Data {
	int year;
	int month;
	int day;
	string name;
	int quantity;
};

int main() {
	
	char st[3];
  
  	string a;
  	cin >> a;
  
  	for(int i=0;i<3;i++){
  		st[i] = a[i];
    }
  	
  	if(st[0] == st[1] && st[1] == st[2]){
      cout << "No";
    }
  	else{
		cout << "Yes";
    }

	return 0;
}
