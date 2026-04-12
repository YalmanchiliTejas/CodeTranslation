#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;


int main()
{
	int n,cnt=0,min,min_i;
	cin >> n;
	
	vector<int> a(n),v(0);
	
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	
	v.push_back(a[0]);
	min = a[0];
	min_i = 0;
	
	for(int i=1;i<n;i++){
		if(min >= a[i]){
			v.push_back(a[i]);
			min_i = v.size() - 1;
			min = a[i];
		}
		else{
			for(int j=0;j<v.size();j++){
				if(a[i] > v[j]){
					if(v[j] == min && j == min_i){
						min = a[i];
					}
					v[j] = a[i];
					break;
				}
			}
		}
	}
	
	cout << v.size() << endl;
			

	return 0;
}