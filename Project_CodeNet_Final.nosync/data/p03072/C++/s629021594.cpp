// B-Great Ocean View.cpp : アプリケーションのエントリ ポイントを定義します。
//

//#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>

using namespace std;


int main()
{
    int N;	
	cin >> N;
	vector<int> H;

	int l;
	for (int i = 0; i < N;i++) {
		cin >> l;
		H.push_back(l);
	}

	int counter = 1;
	int max = H[0];

	for (int i = 1; i < N; i++) {
		if (H[i] >= max) {
			counter++;
			max = H[i];
		}
	}
	cout << counter;

	
	//cin>>N;

    return 0;
}

