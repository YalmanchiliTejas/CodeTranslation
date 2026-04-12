#include<iostream>
#include<algorithm>

using namespace std;

void ng(){
	cout << "Impossible" << endl;
	exit(0);
}

#define INF (1<<29)

int a, b;
int d[108][108];
int c[108][108];

int main(){
	cin >> a >> b;
	for(int i = 1;i <= a;i++){
		for(int j = 1;j <= b;j++){
			cin >> d[i][j];
		}
	}

	for(int i = 0;i <= 100;i++){
		for(int j = 0;j <= 100;j++){
			for(int x = 1;x <= a;x++){
				for(int y = 1;y <= b;y++){
					c[i][j] = max(c[i][j], d[x][y] - x*i - y*j);
				}
			}
		}
	}

	for(int x = 1;x <= a;x++){
		for(int y = 1;y <= b;y++){
			int dist = INF;
			for(int i = 0;i <= 100;i++){
				for(int j = 0;j <= 100;j++){
					dist = min(dist, c[i][j] + x*i+y*j);
				}
			}
			if(dist != d[x][y])ng();
		}
	}
	cout << "Possible" << endl;
	cout << 202 << " " << 101*101 + 200 << endl;
	for(int i = 0;i <= 100;i++){
		int u = i+1;
		for(int j = 0;j <= 100;j++){
			int v = j + 102;
			cout << u << " " << v << " " << c[i][j] << endl;
		}
	}
	for(int i = 0;i < 100;i++){
		int u = i + 1;
		int v = u + 1;
		cout << u << " " << v << " " << "X" << endl;
	}
	
	for(int i = 0;i < 100;i++){
		int v = i + 102;
		int u = v + 1;
		cout << u << " " << v << " " << "Y" << endl;
	}
	cout << 1 << " " << 102 << endl;
	return 0;
}