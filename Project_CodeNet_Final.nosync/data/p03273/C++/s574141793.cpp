#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define str string

int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};

vector <ll> v;
ll Y[10000000] = {}, X[10000000] = {},m = 0,a = 0,b = 0,n = 0, x = 0,y = 0,sum = 0;
char H[100][100] = {};
str S,Sa;
bool ans = true;

int findSumOfDigits(int n) {
	int sum = 0;
	while (n > 0) {
		
		sum += n%10;
		n /= 10;
	}
	return sum;
}

int main(){
cin.tie(0);
ios::sync_with_stdio(false);
		//Code Line
cin >> x >> y;
for(int i = 0;i < x;i++){
	int e = 0;
for(int j = 0;j < y;j++){
cin >> H[i][j];
if(H[i][j] != '.')e++;
}
if(e == 0)Y[i] = 500;
}
for(int j = 0;j < y;j++){
	int e = 0;
for(int i = 0;i < x;i++){
if(H[i][j] != '.')e++;
}
if(e == 0)X[j] = 500;
}
for(int i = 0;i < x;i++){
if(Y[i] == 0){
for(int j = 0;j < y;j++){
if(X[j] == 0)cout << H[i][j];
 
} 
  cout << endl;
}
}
		//Code Line
return 0; 
}
