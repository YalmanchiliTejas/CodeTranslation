#define ffor(i,a,b) for (int i=(a);i<(b);i++)
#define rfor(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define rep(i,n) for (int i=0;i<(n);i++)
#define rrep(i,n) for (int i=(n)-1;i>=0;i--)
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<string>
#include<stack>
#include<queue>
#define SIZE 100001
#define MOD 1000000007
#define INF 100000000
using namespace std;

int main(){
	cin.tie(0);

	int n;
	cin >> n;
	string S[50];
	int key[50][26] = {};


	rep(i,n){
		cin >> S[i];
		for(int j = 0; S[i][j] != '\0'; j++){
			key[i][S[i][j] - 'a']++;
		}
	}

	rep(i,26){
		int cn = 50;
		rep(j,n){
			cn = min(cn,key[j][i]);
		}
		cout<< string(cn,'a'+i);
	}
	cout << endl;

	return 0;
}
