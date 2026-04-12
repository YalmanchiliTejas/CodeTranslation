#include<iostream>

#define rep(i,n) for(int i=0; i<n; i++)

int main(void){
	int m;

	std::cin >> m;

	rep(h,m){
		long int money[101];
		int itr;	//手数料

		long int amount;
		int year;
		int n;

		std::cin >> amount >> year >> n;

		int r;
		double itr_rate;
		int fee;

		int max = 0;

		rep(i,n){
			std::cin >> r >> itr_rate >> fee;

			itr = 0;

			money[i] = amount;

			rep(j,year) {
				if (r == 0) { //単利
					itr += money[i] * itr_rate;
					money[i] -= fee;
				}else{
					money[i] += money[i] * itr_rate;
					money[i] -= fee;
					itr = 0;
				}
			}
			money[i] = money[i] + itr;
			if(max < money[i]){
				max = money[i];
			}
		}

		std::cout << max << std::endl;

	}
	return 0;
}