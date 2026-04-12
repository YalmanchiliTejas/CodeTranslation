#include <iostream>
#include <string>
using namespace std;

enum Way{ LEFT, RIGHT };

string in;
string Left,Right;


void solve()
{
	int way = -1;
	int res = 0;

	for(int i = 0; i < Left.size(); i++)
		if(in[0] == Left[i])
			way = LEFT;
	if(way < 0)
		way = RIGHT;

	for(int i = 1; i < in.size(); i++){
		int j;
		if(way == LEFT){
			for(j = 0; j < Left.length(); j++){
				if(in[i] == Left[j])
					break;
			}
			if(j == Left.length()){
				way = RIGHT;
				res++;
			}
		}
		else{
			for(j = 0; j < Right.length(); j++){
				if(in[i] == Right[j])
					break;
			}
			if(j == Right.length()){
				way = LEFT;
				res++;
			}
		}
	}

	cout << res << endl;
}
						

	

int main(void)
{
	Left += "qwertasdfgzxcvb";
	Right+= "yuiophjklnm";

	while(cin >> in, in[0] != '#')
		solve();
	return 0;
}