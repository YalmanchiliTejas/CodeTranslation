#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 200000;
int arr[maxn];
vector<int> vec;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
		vec.push_back(arr[i]);
	}
	sort(vec.begin(),vec.end());
	float mid = (vec[n/2]+vec[n/2-1])/2.00;
	for(int i=0;i<n;i++){
		if((float)arr[i] < mid){
			///in left
			printf("%d\n",vec[n/2]);
		}
		else{
			printf("%d\n",vec[n/2-1]);
		}
	}
    return 0;
}