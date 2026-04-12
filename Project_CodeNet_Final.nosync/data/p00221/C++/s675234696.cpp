#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include<cstdio>
using namespace std;
int main() {
	int n, m, j, suu;
	while ((cin >> m >> n)&&m!=0||n!=0) {
		int check[1001] = { 0 };
		for (int i = 1; i <= m; i++)check[i] = i;
		j = 1;
		suu = m;
		for (int i = 1; i <=n; i++) {
			string str;
			
			cin >> str;
			if (suu > 1) {
				if (i % 15 == 0 ) {
					if (str != "FizzBuzz") {
						//cout << "1.." << j << endl;
						check[j] = 0;
						suu--;
					}
				}
				else if (i % 3 == 0){ 
					if (str != "Fizz") {
						//cout << "2.." << j << endl;
						check[j] = 0;
						suu--;
					}
				}
				else if (i % 5 == 0 ) {
					if (str != "Buzz") {
						//cout << "3.." << j << endl;
						check[j] = 0;
						suu--;
					}
				}
				else {
					char buf[10] = { NULL }; //buf2[10] = { NULL };
					sprintf(buf,"%d", i);
					//cout << "str?????????" << str << endl;
					//cout <<"buf?????????"<< buf << endl;
					//snprintf(buf, 10, "%s", str);
					if (str!=buf) {
						//cout << "kita";
						check[j] = 0;
						suu--;
					}
				}
				j++;
				int x;
				if(suu>1)
				for ( x = j; check[x] == 0;) {
					x++;
					if (x > m)x = 1;
				}
				j = x;
			}
		}
		int las;
		for (int i = m; i > 0; i--) if (check[i] != 0) {
			las = i; break;
		}
		//cout << "las?????????" << las << endl;
		for (int i = 1; i<=m; i++)
		{
			if (check[i] != 0)
			{
				cout << i;
				if (i<las)
					cout << " ";
			}
		}
		cout << endl;
	}
}