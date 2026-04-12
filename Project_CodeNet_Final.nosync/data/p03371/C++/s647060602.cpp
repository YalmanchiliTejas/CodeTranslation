#include <iostream>
using namespace std;

int main()
{
	int a,b,c,x,y;
	cin >> a >> b >> c >> x >> y;
	int _max = max(x,y);
	int res = 0;
	
	int xt = a*x;
	int yt = b*y;

	int ab = 2*c*(min(x,y));
	int abc = 2*c*(max(x,y));

	if(max(x,y) == y){
		ab += b*(y - x);
	} 
	else if(max(x,y) == x){
		ab += a*(x - y);
	}

	cout << min(min((xt+yt),ab),abc) << endl;
}