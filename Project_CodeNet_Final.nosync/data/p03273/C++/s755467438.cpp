#include<algorithm>
#include<climits>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<iostream>
#include<numeric>
#include<string>
using namespace std;

long gcd(long x, long y) { if (x > y) { return gcd(y, x); } long r; while (y != 0) { r = x % y; x = y; y = r; }return x; }
long lcm(long x, long y) { return(x / gcd(x, y)) * y; }
void indexsort(long* first, long* last, long* func) { sort(first, last, [&](long a, long b) {return func[a] < func[b]; }); }
//--------------------

int main() {

	long H, W; cin >> H >> W;
	char a[1000][1000]; for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) cin >> a[i][j];
	long isallw[1000] = {};//係数H。


	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			//a[i][j]において
			if (a[i][j] == '.') {
			for (int h = 0; h < H; h++) if (a[h][j] == '#') {goto koko;}
             a[i][j] = 'c' ; continue;
             koko:;
			for (int w = 0; w < W; w++) if (a[i][w] == '#') {;goto soko;}
             a[i][j] = 'c' ; continue;
             soko:;
            }
        }
	}

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++) if(a[i][j] != 'c') isallw[i] = 1;
    }    
   
	for (int i = 0; i < H; i++) {
		if (isallw[i] == 0) continue;
		for (int j = 0; j < W; j++) if (a[i][j] != 'c') cout << a[i][j];
		cout << endl;
	}

}