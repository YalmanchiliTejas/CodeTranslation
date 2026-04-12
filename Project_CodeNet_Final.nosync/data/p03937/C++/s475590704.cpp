    #include <iostream>
    #include <vector>
    #include <set>
    #include <queue>
    #include <algorithm>
    #include <string>
    #include <cmath>
    using namespace std;
    #define MAX 100
    int is[MAX];
    int h, w;
    string s[8];
    
    int searchRowEnd(int start, int row) {
        int endCol = -1;
        bool onLoad = false;
        for (int col = 0; col < w; col++) {
            if (endCol == -1) {
                onLoad = col >= start;
            }
            if (!onLoad && s[row][col] == '#' || col == start && s[row][col] != '#') {
                return -1;
            }
            if (onLoad && s[row][col] == '#') {
                endCol = col;
            } else {
                onLoad = false;
            }
        }
        return endCol;
    }
    
    bool judge() {
        int start = 0;
    	for (int row = 0; row < h; ++row) {
    	    start = searchRowEnd(start, row);
    	    if (start == -1) {
    	        return false;
    	    }
    	}
    	return start == w - 1;
    }
    
    int main(void) {
    	cin >> h >> w;
    	for (int i = 0; i < h; ++i) {
    		cin >> s[i];
    	}
    	bool f = judge();
    	cout << (f ? "Possible" : "Impossible") << endl;
    	return 0;
    }