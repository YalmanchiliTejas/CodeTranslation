//「合成抵抗」(https://beta.atcoder.jp/contests/cf16-relay-open/tasks/relay_a)

#include<iostream>


int main(){
	//標準入力
	int r[2];
	std::cin>>r[0]>>r[1];

	//処理
	//1/R3=1/R1+1/R2
	//これを加工してR3=R1R2/(R1+R2)
	double ans=r[0]*r[1];//計算誤差を抑えるため、計算結果の途中経過をdoubleにしておく
	ans=ans/(r[0]+r[1]);

	//出力
	//std::cout<<ans<<std::endl;//桁数の指定がめんどいのでprintfに
	printf("%.8f",ans);

	return 0;
}
