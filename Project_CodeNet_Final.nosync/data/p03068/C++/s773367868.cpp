#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <sstream>

#define ll long long int
#define rep(i,x,y) for(int i=x;i<y;i++)
#define rel(i,x,y) for(int i=x-1;i>=y;i--)
#define all(x) x.begin(),x.end()

using namespace std;

int main(){
	int N;
	cin >> N;
	char S[N];
	cin >> S;
	int K;
	cin >> K;
	char tmp;
	tmp = S[K-1];
	rep(i,0,N){
		if(tmp == S[i]){
			cout << tmp;
		}else{
			cout << "*";
		}
	}
	cout << endl;
}
