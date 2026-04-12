#include <iostream>
#define rep(i,n) for(int i=0; i<n; i++)

int main(void){

	int m;

	std::cin >> m;	//データセットの数

	while(m--){
		double amt;		//初期運用資金量
		int year;		//運用年数
		int n;			//運用方法の種類数
		int ans = 0;

		std::cin >> amt >> year >> n;

		while(n--){

			int f;			//単利０、複利１
			double roi;	//利率
			double chg;	//手数料
			int itr = 0;		//利子
			double fin = 0;	//最終資金

			int amt_tmp = amt;	//資金初期化

			std::cin >> f >> roi >> chg;

			if(f == 0){		//単利

				rep(i,year){
					itr += amt_tmp * roi;
					amt_tmp -= chg;
				}
				fin = amt_tmp + itr;

			}else{			//複利

				rep(i,year){
					amt_tmp += amt_tmp * roi;
					amt_tmp -= chg;
				}
				fin = amt_tmp;

			}
			if(ans < fin){
				ans = fin;
			}
		}

		std::cout << ans <<std::endl;
	}

	return 0;
}