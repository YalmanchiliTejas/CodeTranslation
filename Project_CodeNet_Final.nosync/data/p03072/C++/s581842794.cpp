#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<utility>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;

#define MOD 1000000007;

int main(){
	int n;
	cin >> n;
	vector<int> h(n);
	for(int i=0; i<n; i++)
		cin >> h[i];
	int num=1;
	for(int i=n-1; i>0; i--){
		for(int j=i-1; j>=0; j--){
			if(h[j]>h[i])
				break;
			if(j==0)
				num++;
		}
	}
	cout << num << endl;
	return 0;
}