#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <cstdlib>

using namespace std;

int main(){

	long long  a, b, c, x, y;
	long long  need=0, api=0, bpi=0;
	cin >> a >> b >> c >> x >> y;
	if( (a+b)  <= c * 2 ){
		while( (api<x) && (bpi<y) ){
			need += a + b;
			api++;
			bpi++;
		}
	}
	else{
		while( (api<x) && (bpi<y) ){
			need += c*2;
			api++;
			bpi++;
		}
	}


	if( bpi < y ){  //つまりbが足りていない
		if( c < b/2 ){
			need += c*2*(y-bpi);
		}
		else{
			need += b*(y-bpi);
		}
	}

	else if( api < x ){  //つまりaが足りていない
		if( c < a/2 ){
			need += c*2*(x-api);
		}
		else{
			need += a*(x-api);
		}
	}
	cout << need <<endl;


	return 0;
}
