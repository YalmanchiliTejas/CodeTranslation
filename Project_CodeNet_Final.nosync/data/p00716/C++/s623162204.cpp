#include <iostream>
#include <stdio.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;
int main(){
	long long int start, temp = 0, start2 = 0;
	int year, n, y, m, i, j;
	char a;
	double x;
	int ans[100], count = 0;

	cin >> m;
	for(i = 0;i < m;i++){
		cin >> start >> year >> n;
		for(j = 0;j < n;j++){
			cin >> a >> x >> y;
			start2 = start;
			if(a == '0'){
				for(int k = 0;k < year;k++){
					temp += (int)(start2 * x);
					start2 -= y;
				}
				ans[count] = start2 + temp;
				//cout << ans[count] << " " << start2 << " " << temp << endl;
				temp = 0;
				count++;
			}
			else if(a == '1'){
				for(int k = 0;k < year;k++){
					temp += (int)(start2 * x);
					start2 = start2 + temp - y;
					temp = 0;
				}
				ans[count] = start2;
				//cout << ans[count] << " " << start2 << " " << temp << endl;
				count++;
			}
		}
		sort(ans, ans+count);
		cout << ans[count-1] << endl;
		for(int k = 0;k < count;k++){
			ans[k] = 0;
		}
		count = 0;

	}

	return 0;
}