#include<iostream> 
#include<string> 
using namespace std; 

int main()
{
	int r;
	int g;
	int b;

	cin >> r;
	cin >> g;
	cin >> b;

	while ((g * 10 + b * 1)%4== 0){
		cout << "YES" << endl; 
		break;
	} 
	while ((g * 10 + b * 1)%4!=0) {
		cout << "NO" << endl; 
		break;
	}
}