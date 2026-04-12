#include<cstdio>
#include<vector>
using namespace std;

int n;
vector<int> a,b;

int main(){
	scanf("%d",&n);
	int i;
	for(i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		if(i%2==1)a.push_back(x);
		else b.push_back(x);
	}
	if(n%2==0){
		for(i=b.size()-1;i>=0;i--){
			printf("%d ",b[i]);
		}
		for(i=0;i<a.size();i++){
			printf("%d ",a[i]);
		}
	}
	else{
		for(i=a.size()-1;i>=0;i--){
			printf("%d ",a[i]);
		}
		for(i=0;i<b.size();i++){
			printf("%d ",b[i]);
		}
	}
	return 0;
}
