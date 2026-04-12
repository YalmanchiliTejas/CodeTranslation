
#include <string>
#include <numeric>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	int h[n],highest[n];
	int count = 1;
	for(int i = 0;i < n;i++){
		cin >> h[i];
		if(i==0){
			highest[0] = h[0];
		}else{
			if(h[i] > highest[i-1]){
				highest[i] = h[i];
			}else{
				highest[i] = highest[i-1];
			}
		}
	}
	for(int i = 1;i < n;i++){
		if(h[i] >= highest[i-1]){
			count++;
		}
	}
	cout << count << endl;
}