#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define FOR(i,k,n) for((i)=(k);(i)<(n);(i)++)
#define REP(i,n) for (int i=0;i<(n);i++)
#define pb push_back
#define all(a) (a).begin(),(a).end()  //greater<int>()
using namespace std;

int main(){
	int N,x,y;
	cin>>N;
	x=800*N;
	y=200*int(N/15);
	cout<<x-y<<endl;
   	return 0;
}
