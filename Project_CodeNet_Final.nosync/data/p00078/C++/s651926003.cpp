#include <iostream>
#include <iomanip>

int main() {
	
	int map[15][15];
	int num, x, y, c;

	while(1) {
		// Input a number
		std::cin >> num;
		if(num==0) break;
		
		// Initialize the 'map'
		for( int i=0; i<num*num; i++) map[i%num][i/num] = 0;
		
		// First Position( down one of the middle )
		x = (num-1) / 2; y = (num-1) / 2 + 1;
		c = 1;
		
		// Create 'Magic Square'
		while(1) {

			map[x][y] = c;
			
			if(c==num*num) break;
			c++;
			
			
			// Move Position
			x++; y++;
			
			// If Position is outside 'Magic Square'
			if(x<0) x = num-1;
			if(x>=num) x = 0;
			if(y>=num) y = 0;
			
			if(0<=x && 0<=y && x<num && y<num) {
				// If number is already inputting
				if(map[x][y]!=0) { x--; y++;}
			}
			
			// If Position is outside 'Magic Square'
			if(x<0) x = num-1;
			if(x>=num) x = 0;
			if(y>=num) y = 0;
		}
		
		// Output the 'Magic Square'
		for( int i=0; i<num*num; i++) {
			std::cout << std::setw(4) << map[i%num][i/num] << ( (i%num)==num-1 ? "\n" : "" );
		}
	}
	
	return 0;
}