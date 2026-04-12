#include <bits/stdc++.h>

using namespace std;



int main(){

	while(true){
		int n;
		cin>>n;

		if(n==0) break;

		int max=0;
		int min=1000;
		int sum=0;
		for (int i = 0; i < n; ++i)
		{
			int current;
			cin>>current;
			if(current>max){
				max=current;
			}
			if(current<min){
				min=current;
			}
			sum+=current;
		}

		cout<<(sum-min-max)/(n-2)<<endl;
	}
	
return 0;
}