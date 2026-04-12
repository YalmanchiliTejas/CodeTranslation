#include <iostream>
#include <string>
using namespace std;

int main(void){
	string s;
	cin >> s;
	int count = 0;
	int a[4];
	string b[4];
	//for(int i = 0; i < s.size(); ++i){
	int i = 0;
		for(int j = i+1; j < s.size(); ++j){
			for(int k = j+1; k < s.size(); ++k){
				for(int l = k+1; l < s.size(); ++l){
					b[0] = s.substr(i,j-i);
					b[1] = s.substr(j,k-j);
					b[2] = s.substr(k,l-k);
					b[3] = s.substr(l,s.size());
					bool fl = true;
					for(int p = 0; p < 4; ++p){
						a[p] = stoi(b[p]);
						if(a[p]<0 || a[p] > 255) fl = false;
						if(a[p]==0){
							if(b[p]!="0") fl = false;
						}
						if(a[p]!=0){
							if(b[p][0]=='0') fl = false;
						}
					}
					if(fl){
						count++;
						//cout << a[0] << " "<<  a[1] << " "<< a[2] << " "<< a[3] << " "<< endl;
					}
				}
			}
		}
	//}
	cout << count << endl;
	return 0;
}
