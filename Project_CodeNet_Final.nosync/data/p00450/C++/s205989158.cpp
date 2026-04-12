
#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<list>
#include<set>
#include<stack>
#include<cstdlib>
#include<algorithm>
#include<random>
#include<cassert>
using namespace std;
#define LL long long
#define ROOP() while(true)
int main(){
	ROOP(){
		LL n;
		cin >> n;
		if(n==0) break;
		vector<int> table;
		int first;
		cin >> first;
		table.push_back(1);
		int size = 1;
		
		for(LL i=2; i-1<n; i++){
			int ishi;
			cin >> ishi;
			if(i%2==1){ //奇数
				if(size%2==1){//firstと同じ
					if(ishi==first) table.back() += 1;
					else{
						table.push_back(1);
						size++;
					}
				}
				else{//firstの反対
					if(ishi!=first) table.back() += 1;
					else{
						table.push_back(1);
						size++;
					}
				}
			}
			else{ //偶数
				if(size%2==1){//firstと同じ
					if(ishi==first) table.back() += 1;
					else{
						int tmp = table.back();
						table.pop_back();
						size--;
						if(size<=0){
							table.push_back(0);
							first *= -1;
							first++;
							size++;
						}
						table.back() += tmp + 1;
					}
				}
				else{//firstの反対
					if(ishi!=first) table.back() += 1;
					else{
						int tmp = table.back();
						table.pop_back();
						size--;
						if(size<=0){
							table.push_back(0);
							first *= -1;
							first++;
							size++;
						}
						table.back() += tmp + 1;
					}
				}
			}
		}
		LL ans = 0;
		LL tmp;
		if(first == 0) tmp=0;
		else tmp=1;
		for(LL i=tmp; i<size; i+=2){
			ans += table.at(i);
		}
		cout << ans << endl;
	}
	return 0;
}
