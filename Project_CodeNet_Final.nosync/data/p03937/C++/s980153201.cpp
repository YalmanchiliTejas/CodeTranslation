#include <iostream>
using namespace std;
int h, w, s;
char a;
int main() {
	cin>>h>>w;
	s = h+w-1;
	h *= w;
	while(h--) cin>>a, s -= a=='#';
	cout<<(s ? "Imp":"P")<<"ossible";
	return 0;
}