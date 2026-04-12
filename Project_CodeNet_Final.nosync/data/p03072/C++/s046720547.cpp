#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<cmath>
#include<functional>
#include<iomanip>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<utility>
#include<string>
#include<numeric>
//#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
  	cin >> n;
	auto h = vector<int>(istream_iterator<int>(cin),istream_iterator<int>());
	auto num = vector<int>(n,0);
	
  	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
          	if(h[i] <= h[j]){
            	num[j]++;
            }
		}
	}
	
	int count =1;
	for (int i = 1; i < n; i++)
	{
      if(num[i] == i){
        	count++;
      }
	}
	cout << count;
}