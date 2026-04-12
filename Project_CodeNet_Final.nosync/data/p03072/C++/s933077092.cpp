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
	int H[N];
	int max=0;
	int count=0;
	rep(i,0,N){
		cin >> H[i];
		if(max <= H[i]){
			count++;
			max = H[i];
		}
	}
	cout << count << endl;
	
}