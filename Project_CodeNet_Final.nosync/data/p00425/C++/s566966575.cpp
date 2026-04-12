#include<algorithm>
#include<iostream>
#include<string.h>

int n;
int ans;

int main()
{
	while( 1 ){
		std::cin >> n;
		
		if( !n ) break;
		
		ans = 1;
		
		int num[6] = { 1, 2, 3, 5, 4, 6 };
		int num2[6] = { 1, 2, 3, 5, 4, 6 };
		
		while( n-- ){
			std::copy( num, num + 6, num2 );
			
			char str[10];
		 	std::cin >> str;
			
			if( !strcmp( str, "North" ) ){
			 	num[0] = num2[1];
				num[1] = num2[5];
				num[5] = num2[3];
				num[3] = num2[0];
			}
			else if( !strcmp( str, "East" ) ){
			 	num[2] = num2[0];
				num[0] = num2[4];
				num[4] = num2[5];
				num[5] = num2[2];
			}
			else if( !strcmp( str, "West" ) ){
			 	num[0] = num2[2];
				num[2] = num2[5];
				num[5] = num2[4];
				num[4] = num2[0];
			}
			else if( !strcmp( str, "South" ) ){
			 	num[0] = num2[3];
				num[3] = num2[5];
				num[5] = num2[1];
				num[1] = num2[0];
			}
			else if( !strcmp( str, "Right" ) ){
			 	num[1] = num2[2];
				num[2] = num2[3];
				num[3] = num2[4];
				num[4] = num2[1];
			}
			else if( !strcmp( str, "Left" ) ){
			 	num[2] = num2[1];
				num[1] = num2[4];
				num[4] = num2[3];
				num[3] = num2[2];
			}
			
			ans += num[0];
		}
		
		std::cout << ans << std::endl;
	}

 	return 0;
}