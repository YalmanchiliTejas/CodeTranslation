
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <complex>
#include <vector>

using namespace std;

bool solve(){
	int z;
	cin >>z;
	char a[110][1010];
	int cnt[110]={0};
	
	while(1){
		string str;
		cin >> str;
		int num;
		cin >> num;
		if(str=="quit") return false;
		if(str=="move"){
			int num2;
			cin >> num2;
			cnt[num]--;
			a[num2][cnt[num2]] = a[num][cnt[num]];
			cnt[num2]++;
		}
		if(str=="push"){
			char in;
			cin >> in;
			a[num][cnt[num]] = in;
			cnt[num]++;
		}
		if(str=="pop"){
			cnt[num]--;
			cout<< a[num][cnt[num]]<< endl;
		}
	}
	return true;
}

int main(){
	cout.setf(ios::fixed);
	cout.precision(10);
	solve();

	return 0;
}

 