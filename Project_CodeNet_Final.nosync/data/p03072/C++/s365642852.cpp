//ABC124B
#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <math.h>
using namespace std;

int main(){
	int n;
	int count = 1;
	cin >> n;
	vector <int> a(n);
	for(int i=0;i<n;i++){
		cin >> a.at(i);
	}
	int highest = a.at(0);
	for(int i=1;i<n;i++){
		if(highest <= a.at(i)){
			count++;
		}else{
			count = count;
		}
		highest = max(highest,a.at(i));
	}
	cout << count << endl;
}