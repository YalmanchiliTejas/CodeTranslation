#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <sstream>
 
#define INPUT_FROM_FILE (0) 
#if INPUT_FROM_FILE
#include <fstream>
#endif

int main(int argc, char **argv){
	int n;

#if INPUT_FROM_FILE
	std::ifstream ifs("test.txt");
	std::cin.rdbuf(ifs.rdbuf());
#endif

	while(std::cin >> n){
		if(n == 0){ break; }
		int x = n / 2;
		int y = n / 2 + 1;
		int cn = 2;
		std::vector<std::vector<int> > ms(n, std::vector<int>(n, 0));

		ms[y][x] = 1;
		while(true){
			bool is_filled = true;
			for(int y = 0; y < n; y++){
				for(int x = 0; x < n; x++){
					if(ms[y][x] == 0){
						is_filled = false;
						y = n;
						break;
					}
				}
			}

			if(is_filled){
				break;
			}

			x++;
			y++;
			while(true){
				if(x > n - 1){
					x = 0;
					continue;
				}
				else if(x < 0){
					x = n - 1;
					continue;
				}
				else if(y > n - 1){
					y = 0;
					continue;
				}
				else if(ms[y][x] != 0){
					x--;
					y++;
					continue;
				}

				ms[y][x] = cn++;
				break;
			}
		}

		for(int y = 0; y < n; y++){
			for(int x = 0; x < n; x++){
				printf("%4d", ms[y][x]);
			}
			printf("\n");
		}
	}


#if INPUT_FROM_FILE
		//fclose(fp);
#endif
	return 0;
}

