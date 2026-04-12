#include <iostream>

using namespace std;

int d[10][10];
int c[101][101];

int main(){
	int a,b;
	cin >> a >> b;

	for(int i=0; i<a; i++)
		for(int j=0; j<b; j++)
			cin >> d[i][j];

	for(int kx=0; kx<=100; kx++){
		for(int ky=0; ky<=100; ky++){
			int res = 0;

			for(int i=1;i<=a;i++){
				for(int j=1;j<=b;j++){
					if(res < d[i-1][j-1] - kx*i - ky*j)
						res = d[i-1][j-1] - kx*i - ky*j;
				}
			}
			c[kx][ky] = res;
		}
	}

	for(int i=1;i<=a;i++)
		for(int j=1;j<=b;j++){
			int res = 100;

			for(int kx=0; kx<=100; kx++)
				for(int ky=0; ky<=100; ky++){
					if(res > kx*i + ky*j + c[kx][ky])
						res = kx*i + ky*j + c[kx][ky];
				}

			if(res != d[i-1][j-1]){
				cout << "Impossible" << endl;
				return 0;
			}

		}


	cout << "Possible" << endl;
	cout << "202 10401" << endl;

	for(int i=1;i<=100;i++){
		cout << i <<"  "<< i+1 <<" X"<<endl;
		cout << i+101 <<" "<< i+102 <<" Y"<<endl;
	}

	for(int kx=0; kx<=100; kx++){
		for(int ky=0; ky<=100; ky++){
			cout << kx+1 <<" "<<202 - ky<<" "<< c[kx][ky] <<endl;
		}
	}

	cout << "1 202" << endl;

	return 0;
}
