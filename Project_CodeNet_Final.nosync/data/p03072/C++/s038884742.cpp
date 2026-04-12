#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> h(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> h.at(i);
	}
	vector<int> max(n);
	max.at(0)=h.at(0);
	int count;
	for (int i = 0; i < n-1; ++i)
	{
		if(max.at(i)>h.at(i+1)){
			max.at(i+1)=max.at(i);
		}
		else{
			max.at(i+1)=h.at(i+1);
			count++;
		}
	}
  cout << count+1 << endl;
}
