#include<iostream>
#include<string>
#define MAX 100
#define MAX2 1000
using namespace std;

int main(){
    int n,number,number1,number2;
	char letter[10] ;
	int count[100] = {0} ;

	cin >> n ;

	char str[MAX][MAX2] ;
	char x ;

	while(1){
		cin >> letter ;

		if(letter[2] == 's') {
			cin >> number >> x ;

			str[number-1][count[number-1]] = x ;
			count[number-1]++;
		}

		if(letter[2] == 'p') {
			cin >> number ;
			cout << str[number-1][count[number-1]-1] << endl ;
			count[number-1]--;
		}

		if(letter[0] == 'm') {
			cin >> number1 >> number2 ;

			str[number2-1][count[number2-1]] = str[number1-1][count[number1-1]-1] ;

			count[number1-1]--;
			count[number2-1]++;

		}

		if(letter[0] == 'q') break ;
		
	}
    return 0;
}