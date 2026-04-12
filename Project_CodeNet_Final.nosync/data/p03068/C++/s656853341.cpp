#include <iostream>
using namespace std;
int main (){
	string str;
	int n;
	int k;
	cin >> n ;
	cin >> str;
	cin >> k;
	//vector <char> a(str.size());
	//for (int i =0;i<str.size();i++){
	//	a[i] = str[i];
	//}
	char chara;
	for (int i =0;i<n;i++){
		if(i == k-1){
			chara = str[i];
		}
	}
	for (int i =0;i<n;i++){
		if(str[i] != chara){
			str[i] = '*';
		}
	}
	
	cout << str <<endl; 
}
