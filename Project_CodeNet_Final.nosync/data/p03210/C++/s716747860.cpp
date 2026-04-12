// ABC001C.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//
#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>

using namespace std;




int main()
{
	int old;
	cin>>old;
	if(old == 3 || old == 5 || old == 7){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}

