
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;

int m,n;
char talk[1024],num[200];

int main(){
	int i;
	while( cin >> m >> n ){
		int kill[1000] = {0};
		int surcnt = m;
		int man = 0;
		if( m == 0 && n == 0 )
			break;
		for( i = 1;i <= n;i++ ){

			cin >> talk;
			if( surcnt == 1 )
				continue;
			if( i % 15 == 0 )
				strcpy( num,"FizzBuzz" );
			else if( i % 5 == 0 )
				strcpy( num,"Buzz" );
			else if( i % 3 == 0 )
				strcpy( num,"Fizz" );
			else
				sprintf( num,"%d",i );
			if( strcmp( talk,num ) != 0 ){
				kill[ man ] = 1;
				surcnt--;
			}
			if( surcnt == 1 )
				continue;
			do{
				man++;
				man %= m;
			}while( kill[ man ] );
		}

		int maxsur;
		for( i = m-1;i >= 0;i-- ){
			if( kill[i] == 0 ){
				maxsur = i;
				break;
			}
		}
		for( i = 0;i <= maxsur;i++ ){
			if( kill[i] == 0 ){
				cout << i+1;
				if( i < maxsur ){
					cout << " ";
				}
				else{
					cout << endl;
				}
			}
		}
	}
	return 0;
}