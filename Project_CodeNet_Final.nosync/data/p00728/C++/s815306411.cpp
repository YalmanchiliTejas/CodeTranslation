#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 100000000;

int main(){
	int size;
	while(cin >> size,size!=0){
		//sizeに標準入力して、その値が0でない間ループ
		//while(cin >> size,size)と書く人のほうが多い(意味は同じ)。ソースを読むときの参考に
		//scanfを使う場合はcin >> size の部分をscanfで入力するようにすればよい。
		int maxv = -INF;
		int minv = INF;
		int sum = 0;
		for(int i=0;i<size;i++){
			int num;
			cin >> num;
			sum+=num;
			maxv = max(maxv,num);
			minv = min(minv,num);
		}
		int result = (sum-minv-maxv)/(size-2);
		cout << result << endl;
	}
}