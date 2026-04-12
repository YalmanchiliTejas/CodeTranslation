#include<iostream>
#include<stdio.h>
using namespace std;

int m;
int inis;
int year,n;

int type;
double ritu;
int tesu;

int main(){
	int t;
	int i,j;
	int output;
	int a,b;
	
	cin >> m;
	for( t = 0; t < m; t++ ){
		if( scanf("%d",&inis) != 1 )break;
		cin >> year >> n;
		
		output = 0;
		for( i = 0; i < n; i++ ){
			cin >> type >> ritu >> tesu;
			if( type == 0 ){
				a = inis; b = 0;
				for( j = 0; j < year; j++ ){
					b += (double)a*ritu;
					a -= tesu;
				}
				//cout << "tanri = " << a + b << endl;
			}
			else{
				a = inis; b = 0;
				for( j = 0; j < year; j++ ){
					a = (double)a*(ritu+1.0);
					a -= tesu;
				}
				//cout << "fukuri = " << a + b << endl;
			}
			output = max( a+b, output );
		}
		cout << output << endl;
	}
	return 0;
}