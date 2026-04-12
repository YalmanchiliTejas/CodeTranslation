#include <iostream>
#include <string>

using namespace std;

int main(){
 	string a,b,c;
  	cin >> a >> b >> c;

  	a = a + b + c;

    int num = stoi(a);
  	if(num%4 == 0){
		cout << "YES";
    }else{
     	cout << "NO";
    }

}
