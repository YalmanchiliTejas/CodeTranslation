#include<iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
#define rep(i,ra,re) for((i)=ra;(i)<(re);(i)++)
#define rep_(i,ra,re) for((i)=ra;(i)<=(re);(i)++)
#define pu(n) cout << n; 
#define put(n) cout << n << " "; 
#define puts(n) cout << n << endl;
int a,b,i;
string h;
char f;
int main(void){
	cin >> a >> h >> b;
	f=h[b-1];
	rep(i,0,a){
		if(h[i]==f){
			pu(h[i]);}
		else{
			cout << "*" ;}
	}
	cout << endl;
	return 0;
}