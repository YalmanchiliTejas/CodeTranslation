#include <iostream>
using namespace std;
int X,Y,N;
int main() {
	cin>>N;
	X = N * 800;
	Y = N/15 * 200;
	cout<<X - Y<<endl;
}