#include <vector>
#include <iostream>
#include <stdio.h>


using namespace std;

#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 

int search(int now, int path, int goal, int n, bool *paths) {
	if ( path == goal )
		return 1;

	int sum = 0;
	for(int i=0; i < n; i++) {
		bool next = paths[now * n + i];
		if (next) {
			int position = 1 << i;
			if ((path & position) == 0){
				sum += search(i, path | position, goal, n, paths);
			}
		}
	}
	return sum;
}

void solv(int n, std::vector<std::vector<int> > pairs) {
	n++;
	int path = 3;
	int goal = 0;
	for(int i=0; i < n; i++) {
		goal += 1 << i;
	}

	bool paths[n][n];
	for(int i=0; i <n; i++){
		for(int j=0; j<n+1; j++) {
			paths[i][j] = false;
}
}

for(int i=0; i < pairs.size(); i++){
	int from = pairs[i][0];
	int to = pairs[i][1];
	paths[from][to] = true;
	paths[to][from] = true;
}
    int now = 1;
	int ret = search(now, path, goal, n, &paths[0][0]);

	std::cout << ret << std::endl;
}

int main(void) {
    int N;
    std::cin >> N;
    int M;
    std::cin >> M;

    std::vector<std::vector<int> >pairs(M, std::vector<int>(2, 0));
    for(int i=0; i<M; i++) {
        std::cin >> pairs[i][0];
        std::cin >> pairs[i][1];        
    }

    solv(N, pairs);

    return 0;
}


