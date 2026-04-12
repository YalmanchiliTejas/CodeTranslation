#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int cl(int a, int b) {
	return (a - (a%b)) / b;//b=0だと積む
}
int up(int a, int b) {
	return cl(a + b - 1, b);//b=0だと積む
}
int ord(int a, int p) {
	if (a%p == 0) {
		return ord(a / p, p) + 1;
	}
	else {
		return 0;
	}
}
int main() {
	int n;
	cin >> n;
	while(n!=0)
	{
	int ans = 0;
	vector<int> go(n);
	int ch, ba,fi;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (i == 0) {
			go[0] = 1;
			ch = 0;
			fi = x;
		}
		else if (i % 2 == 0) {
			if(x != ba){
				ch++;
			}
			go[ch]++;
		}
		else {
			if (x == ba) {
				go[ch]++;
			}
			else {
				if (ch == 0) {
					go[ch]++;
					fi = (fi + 1) % 2;
				}
				else {
					go[ch - 1] = go[ch - 1] + go[ch] + 1;
					go[ch] = 0;
					ch = ch - 1;
				}
			}
		}
		ba = x;
	}
	int wh = 1 - fi;
	for (int i = 0; i < n; i++) {
		ans = ans + wh * go[i];
		wh = 1 - wh;
	}
	cout << ans<<endl;
	cin >> n;
	}
	return 0;
}

