#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n;
	int s;
	int min = 10000;
	int max = 0;
	int sum = 0;
	vector<int> results;
	while(cin>>n){
		if(n==0){
			break;
		}
		for(int j = 0;j<n;j++){
                    cin>>s;
		    sum+=s;
		    if(s>max)
                       max = s;
                    if(s<min)
                       min = s;
		}
		sum = (sum-max-min)/(n-2);
                results.push_back(sum);
                min = 10000;
                max = 0;
                sum = 0;
	}
	int size = results.size();
	for(int i = 0;i<size;i++){
		cout<<results[i]<<endl;
	}
}

