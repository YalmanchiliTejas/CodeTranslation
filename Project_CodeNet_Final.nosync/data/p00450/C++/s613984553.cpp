#include <iostream>

using namespace std;

int main()
{
	int n,*in,*table,cnt = 0;


	in = new int[100000];
	table = new int[100000];

	cin >> n;

	while(n != 0){

	for(int i = 0; i < n; i++){
		cin >> in[i];
	}

	for(int i = 0; i < n; i++){
		table[i] = in[i];
		if(i%2 == 1){
			for(int j = i-1; table[j] != in[i] && j >= 0; j--){
				table[j] = in[i];
			}
		}
	}

	cnt = 0;
	for(int i = 0; i < n; i++){
		if(table[i] == 0){
			cnt++;
		}
	}

	cout << cnt << endl;

	cin >> n;
	}

	return 0;
}