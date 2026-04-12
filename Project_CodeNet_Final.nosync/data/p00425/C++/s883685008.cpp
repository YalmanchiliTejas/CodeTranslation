#include <iostream>
#include <string>
using namespace std;

int main(){
	int t, s, e, r, n, m;
	string cntr;
	while(cin >> n, n != 0){
		r = 1;
		t = 1;
		s = 2;
		e = 3;
		for(int i = 1; i <= n; i++){
			cin >> cntr;
			m = t;
			if(cntr == "North"){
				t = s;
				s = 7-m;
			}
			else if(cntr == "East"){
				t = 7-e;
				e = m;
			}
			else if(cntr == "West"){
				t = e;
				e = 7-m;
			}
			else if(cntr == "South"){
				t = 7-s;
				s = m;
			}
			else if(cntr == "Right"){
				m = s;
				s = e;
				e = 7-m;
			}
			else if(cntr == "Left"){
				m = e;
				e = s;
				s = 7-m;
			}
			r += t;	
		}
		cout <<  r << endl;
	}
	return 0;
}