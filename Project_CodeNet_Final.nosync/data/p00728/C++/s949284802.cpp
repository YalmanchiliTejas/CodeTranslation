#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> array;
	vector<int> ans;
	int i,x,max,min,sum,n;


	while(1){
	cin>>n;
	max = 0;
	min = 1000;
	if(n==0){
		for(i=0;i<ans.size();i++){
			cout<<ans[i]<< endl;
		}

		break;
	}
	array.clear();
	sum=0;

	for(i=0;i<n;i++){
		cin >> x;
		array.push_back(x);
	}
	for(i=0;i<n;i++){
		if(max<array[i]){
			max= array[i];
		}
	}
	for(i=0;i<n;i++){
		if(min>array[i]){
			min= array[i];
		}
	}
	for(i=0;i<n;i++){
		sum += array[i];
	}
	sum = sum-max-min;
	ans.push_back(sum/(n-2));  //2ひいた分だけ割る数を減らす 
	}

}