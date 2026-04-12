#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

const int s=1001;

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long int a,b,c,x,y,mini;
	long long int ans;
	cin >> a >> b >> c >> x >> y;

	if(a+b <= 2*c){
		ans = a*x + b*y;
	}else{
		mini = min(x,y);
		ans = mini * c * 2;
		x -= mini;
		y -= mini;
		if(x == 0 && y != 0){
			if(b <= 2*c){
				ans += b * y;
			}else{
				ans += c * y * 2;
			}
		}else if(y == 0 && x != 0){
			if(a <= 2*c){
				ans += a * x;
			}else{
				ans += c * x * 2;
			}
		}
	}
	cout << ans << "\n";

	return 0;
}