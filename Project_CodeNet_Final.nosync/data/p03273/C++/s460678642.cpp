#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <queue>//for queue and priority_queue
#include <fstream>
#include <iomanip>
#include <stack>
#include <algorithm>
#include <set>
#include <map>
#include <list>
#define endl "\n"
typedef long long ll;
using namespace std;
void Lancer() { ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); }
bool isPrime(ll n){
	if (n == 2 || n == 3 || n == 5)
		return true;
	else if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n == 1)
		return false;
	else {
		for (int i = 5; i <= sqrt(n); i += 2){
			if (n%i == 0)
				return false;
		}
		return true;
	}
}

char arr[107][107];
int main(){
	Lancer();
	ll r, c, t;
	cin >> r >> c;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> arr[i][j];
	for (int i = 0; i < r; i++){
		t = 0;
		for (int j = 0; j < c; j++){
			if (arr[i][j] == '.')
				t++;
		}
		if (t == c){
			for (int j = 0; j < c; j++){
				arr[i][j] = 'w';
			}
		}
	}
	
	
	for (int i = 0; i < c; i++){
		t = 0;
		for (int j = 0; j < r; j++){
			if (arr[j][i] == '.' || arr[j][i] == 'w')
				t++;
		}
		if (t == r){
			for (int j = 0; j < r; j++)
				arr[j][i] = 'w';
		}
	}
	for (int i = 0; i < r; i++){
		bool ch = false;
		for (int j = 0; j < c; j++){
			if (arr[i][j] != 'w'){
				cout << arr[i][j];
				ch = true;
			}
		}
		if(ch) cout << endl;
	}
	//cout << endl;
	return 0;
}
