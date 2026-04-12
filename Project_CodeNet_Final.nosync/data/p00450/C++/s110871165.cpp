#include <iostream>
#include <bitset>
#include <vector>
using namespace std;
typedef long long ll;

const int MAX_N = 100000;

int main()
{
	int n;
	while(cin >> n && n){

		vector<int> lengh(n);
		int left, right = 0, before;
		lengh[right] = 1;

		for(int i = 0; i < n; i++){

			int buf;
			cin >> buf;

			if(i){

				if(before == buf){

					lengh[right]++;

				}else if((i+1) % 2 == 0){

					if(right == 0){

						lengh[right]++;
						left = buf;

					}else{

						lengh[right - 1] += lengh[right] + 1;
						lengh[right] = 0;
						right--;

					}
				}else{

					right++;
					lengh[right] = 1;

				}

			}else	left = before = buf;

			before = buf;
		}

		int res = 0;
		for(int i = 0; i < lengh.size(); i++){
			if(!left) res += lengh[i];
			left = !left;
		}

		cout << res << endl;
	}
}