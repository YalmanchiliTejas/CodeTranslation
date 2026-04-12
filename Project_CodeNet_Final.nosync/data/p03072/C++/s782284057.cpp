#include<iostream>
#include<vector>
using namespace std;
int len, ans, nowmax;
int h[20];
int main(){
	cin >> len;
	for(int i = 0;i < len;++i){
		cin >> h[i];
		if(h[i] >= nowmax){
			++ans;
			nowmax = h[i];
		}
	}
	cout << ans << '\n';
}